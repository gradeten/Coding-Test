SELECT i.ANIMAL_ID, i.NAME
FROM ANIMAL_INS i, ANIMAL_OUTS o
WHERE i.ANIMAL_ID = o.ANIMAL_ID AND o.DATETIME < i.DATETIME
ORDER BY i.DATETIME ASC;