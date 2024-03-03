
struct One
{
    int d;
    char s;
};

int r = 99;
One fun(One x)
{
    
    x.d = 5;
    x.s = 'k';
    return x;
}
int main()
{
    One d;
    One two = fun(d);
    int zz = 4;
    return 0;
}