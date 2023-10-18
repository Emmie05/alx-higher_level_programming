-- List all records from the table second_table with a name value, ordered by descending score
SELECT score, name FROM second_table
WHERE name IS NOT NULL AND name != ''
ORDER BY score DESC;
