const getGCD = (num1, num2) => (num2 > 0 ? getGCD(num2, num1 % num2) : num1);
