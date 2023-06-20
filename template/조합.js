const getCombinations = function (arr, selectNumber) {
  const results = [];
  if (selectNumber === 1) return arr.map((el) => [el]);

  arr.forEach((fixed, index, origin) => {
    const rest = origin.slice(index + 1);
    const combinations = getCombinations(rest, selectNumber - 1);
    const attached = combinations.map((el) => [fixed, ...el]);
    results.push(...attached);
  });
  return results; // 결과 담긴 results return
};

const result = getCombinations([1, 2, 3, 4], 2);
console.log(result);

const getCombination2 = (arr, n, r, index, depth) => {
  if (r === 1) return arr.map((el) => [el]);
  if (r === n) return arr.filter((el, i) => i - index < n && i - index >= 0);
  else
    return [
      getCombination2(arr, n - 1, r - 1, index),
      getCombination2(arr, n - 1, r, index + 1),
      ,
    ];
};

/**
 * 3C2 = 2C1 + 1C1 + 1C0
 */

console.log(getCombination2([1, 2, 3], 3, 3, 0));
console.log(getCombination2([1, 2, 3], 3, 1, 0));
console.log(getCombination2([1, 2, 3], 3, 2, 0));
