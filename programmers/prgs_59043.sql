--있었는데요 없었습니다
SELECT
 AI.ANIMAL_ID, AI.NAME
FROM ANIMAL_INS as AI
INNER JOIN ANIMAL_OUTS as AO
ON AI.ANIMAL_ID = AO.ANIMAL_ID AND AI.DATETIME > AO.DATETIME
ORDER BY AI.DATETIME;