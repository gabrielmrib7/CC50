SELECT name from songs
where artist_id = (SELECT id from artists where name = "Post Malone");