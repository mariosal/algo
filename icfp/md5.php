<?php
    exec( 'gcc palindrome.c' );
    $string = exec( './a.out < endo.dna' );
    exec( 'rm ./a.out' );
    echo md5( $string ), "\n";
?>
