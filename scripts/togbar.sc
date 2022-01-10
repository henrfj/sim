if [ $# -ne 1 ] ; then
echo "missing study number"
else
scp * $1@login.gbar.dtu.dk:smr/
fi