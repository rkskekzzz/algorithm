const isPrime = (num) =>
  Array(Math.floor(Math.sqrt(num)))
    .fill()
    .filter((_, i) => num !== 1 && num % (i + 1) === 0).length;

const getPermutations = function (arr, selectNumber) {
  const results = [];
  if (selectNumber === 1) return arr.map((el) => [el]);

  arr.forEach((fixed, index, origin) => {
    const rest = [...origin.slice(0, index), ...origin.slice(index + 1)];
    const permutations = getPermutations(rest, selectNumber - 1);
    const attached = permutations.map((el) => [fixed, ...el]);
    results.push(...attached);
  });

  return results;
};

const solution = (numbers) =>
  [
    ...new Set(
      Array(numbers.length)
        .fill()
        .reduce(
          (acc, _, i) => [
            ...acc,
            ...getPermutations([...numbers], i + 1)
              .map((e) => e.join(''))
              .map((e) => parseInt(e)),
          ],
          []
        )
    ),
  ].filter((e) => isPrime(e) === 1).length;
