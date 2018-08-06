print "Hello World\n";
$s = qx/ls -l/;
print "$s";
$s = qx/python --version/;
print "$s";
$s = qx/perl -v/;
print "$s";
## open(DATA, ">output.txt"); or die "No";
