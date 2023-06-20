/*
 * `codeOwnersMap`과 `directory`를 입력받아
 * `directory`의 코드 주인 목록을 반환하는 함수를 작성하세요.
 */

function solution(codeOwnersMap, directory) {
  const directoryDepthArray = directory.split('/');
  // const codeOwners;
  for (directoryDepth of directoryDepthArray) {
    codeOwnersMap = codeOwnersMap.get(directoryDepth);
  }
  console.log(codeOwnersMap);
  return [];
}

solution();

const findDeployDate = (acc, cur, idx, ori) => {
  if (idx > 0) {
    return [...acc, ori[idx] > acc[idx - 1] ? ori[idx] : acc[idx - 1]];
  } else {
    return [...acc];
  }
};

const solution = (progresses, speeds) => {
  const 남은날 = progresses.map((e, idx) => Math.ceil((100 - e) / speeds[idx]));
  const 배포일 = 남은날.reduce(findDeployDate, [남은날[0]]);
  const 배포날짜별개수 = new Map();
  배포일.forEach((e) =>
    배포날짜별개수.set(e, 배포날짜별개수.get(e) ? 배포날짜별개수.get(e) + 1 : 1)
  );

  return [...배포날짜별개수.values()];
};

const reducedUser = state.users.reduce((user: UserWithValid[], cur: User) => {
  curentUser.schedules.forEach((schedule) => {
    if (day.moment.isSame(_schedule.start, 'day')) {
      user.push({
        info: cur,
        valid: _schedule.valid,
      });
    }
  });
  return user;
}, []);
