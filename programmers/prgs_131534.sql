-- 상품을 구매한 회원 비율 구하기
SELECT
    YEAR(OS.SALES_DATE) as YEAR,
    MONTH(OS.SALES_DATE) as MONTH,
    COUNT(DISTINCT OS.USER_ID) as PUCHASED_USERS,
    ROUND(COUNT(DISTINCT OS.USER_ID)/ (SELECT COUNT(*) FROM USER_INFO WHERE YEAR(JOINED) = 2021), 1) as PUCHASED_RATIO
FROM ONLINE_SALE AS OS
INNER JOIN USER_INFO as UI
ON UI.USER_ID = OS.USER_ID AND YEAR(UI.JOINED) = 2021
GROUP BY YEAR(OS.SALES_DATE), MONTH(OS.SALES_DATE)
ORDER BY YEAR ASC, MONTH ASC;