const dirs = [
  [1, 0],
  [0, 1],
  [-1, 0],
  [0, -1],
];

const isOnMap = (x, y, maps) =>
  x >= 0 && y >= 0 && x < maps.length && y < maps[0].length && maps[x][y] === 1;

const solution = (maps) => {
  a = -1;
  queue = [[0, 0]];
  const bfs = () => {
    if (queue.length === 0) return;
    const [x, y] = queue.shift();
    if (x === maps.length - 1 && y === maps[0].length - 1) {
      a = maps[x][y];
      queue = [];
    } else {
      dirs.forEach(([dx, dy]) => {
        if (isOnMap(x + dx, y + dy, maps)) {
          maps[x + dx][y + dy] = maps[x][y] + 1;
          queue.push([x + dx, y + dy]);
        }
      });
      bfs();
    }
  };
  bfs();
  return a;
};

const solution2 = (m) => (
  (a = -1),
  ((q) => (
    (f = () =>
      q.length &&
      (([x, y] = q.shift()),
      x === m.length - 1 && y === m[0].length - 1
        ? (a = m[x][y])
        : [
            [1, 0],
            [0, 1],
            [-1, 0],
            [0, -1],
          ].forEach(
            ([dx, dy]) =>
              !(
                x + dx < 0 ||
                y + dy < 0 ||
                x + dx >= m.length ||
                y + dy >= m[0].length ||
                m[x + dx][y + dy] !== 1
              ) && ((m[x + dx][y + dy] = m[x][y] + 1), q.push([x + dx, y + dy]))
          ),
      f())),
    f()
  ))([[0, 0]]),
  a
);

['POOOP', 'OXXOX', 'OPXPX', 'OOXOX', 'POXXP'];
