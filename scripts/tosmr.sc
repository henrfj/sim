if [ $# -ne 1 ] ; then
echo "missing group number"
else
scp * k385h$1@tustin.iau.dtu.dk:live/
fi
