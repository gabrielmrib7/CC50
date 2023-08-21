SELECT DISTINCT(NAME) FROM PEOPLE P
JOIN STARS S ON S.PERSON_ID = P.ID
JOIN MOVIES M ON M.ID = S.MOVIE_ID
WHERE title IN (SELECT DISTINCT(title) from movies
JOIN stars on movies.id = stars.movie_id
JOIN people on people.id = stars.person_id
WHERE people.name = "Kevin Bacon" AND birth = 1958) AND name != "Kevin Bacon";