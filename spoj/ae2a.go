package main

import "fmt"

func main() {
  const (
    // After this point probability is near 0
    MAX_THROWS = int16(533)
    MAX_SUM = int16(1857)
  )

  // Allocating
  prob := make([][]float32, MAX_THROWS)
  for i := int16(0); i < MAX_THROWS; i++ {
    prob[i] = make([]float32, MAX_SUM)
  }

  // Precomputing
  prob[0][0] = 1
  for i := int16(1); i < MAX_THROWS; i++ {
    for j := int16(1); j < MAX_SUM; j++ {
      if j > 6 * i { // Cannot get sum greater than 6 * i
        break
      }

      switch j {
        case 1:
          prob[i][j] = prob[i - 1][j - 1]
        case 2:
          prob[i][j] = prob[i - 1][j - 1] + prob[i - 1][j - 2]
        case 3:
          prob[i][j] = prob[i - 1][j - 1] + prob[i - 1][j - 2] +
                       prob[i - 1][j - 3]
        case 4:
          prob[i][j] = prob[i - 1][j - 1] + prob[i - 1][j - 2] +
                       prob[i - 1][j - 3] + prob[i - 1][j - 4]
        case 5:
          prob[i][j] = prob[i - 1][j - 1] + prob[i - 1][j - 2] +
                       prob[i - 1][j - 3] + prob[i - 1][j - 4] +
                       prob[i - 1][j - 5]
        default:
          prob[i][j] = prob[i - 1][j - 1] + prob[i - 1][j - 2] +
                       prob[i - 1][j - 3] + prob[i - 1][j - 4] +
                       prob[i - 1][j - 5] + prob[i - 1][j - 6]
      }
      prob[i][j] /= 6
    }
  }

  var tests int32
  fmt.Scanf("%d", &tests)

  for i := int32(0); i < tests; i++ {
    var (
      throw_times int32
      desirable_sum int32
    )
    fmt.Scanf("%d%d", &throw_times, &desirable_sum)

    if throw_times >= int32(MAX_THROWS) || desirable_sum >= int32(MAX_SUM) {
      fmt.Printf("0\n") // Probability is near 0
    } else {
      probability := int8(100 * prob[throw_times][desirable_sum])
      fmt.Printf("%d\n", probability)
    }
  }
}
