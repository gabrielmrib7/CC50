SELECT avg(energy) from songs
where artist_id = (SELECT id from artists where name = "Drake");o