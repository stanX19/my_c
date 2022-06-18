int reverse(int x){
    int val = 0;
    int charge = 1;
    if (x == -2147483648)
        return 0;
    if (x < 0) {
        charge = -1;
        x = -x;
    }
    while (0 < x){
        if ((val >= 214748364 && x > 7) || val >= 214748365)
            return 0;
        val = val * 10 + (x % 10);
        x/=10;
    }
    return (val * charge);
}
