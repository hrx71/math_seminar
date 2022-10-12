int
modulo(int a, int b)
{
    int res = a % b;
    if(res<0) 
    {
	res +=b;
    }
    return res;
}
