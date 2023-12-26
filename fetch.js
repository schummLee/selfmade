// Authorization token that must have been created previously. See : https://developer.spotify.com/documentation/web-api/concepts/authorization
const token = 'BQAIQ4miwGGq6Y3GXEdu4PQlcY07NG3TBwnHUdFAsVnqn6Wfp95LCk7LMQabWlcD_8jH1dioWNOjIdYWRxXUjP4QYrqYlbz_ev7ubLFQi8vei0zGqEfVJd4KCIh8OBZ--LslaPSYMT69oAxwuDOAgwD7fijyFTdTB20X3H6Go6tg1Xv8ZkHpCBOSpPwJpJHFqLRJLYw-_ArDRohqv9TVCKXCOMDEQ_jf85Iiio9StAdemTlCrxyeFy9DQphy5qt_3niUiuIqjVVRkrfbsT9jZra1Jddk';
async function fetchWebApi(endpoint, method, body) {
  const res = await fetch(`https://api.spotify.com/${endpoint}`, {
    headers: {
      Authorization: `Bearer ${token}`,
    },
    method,
    body:JSON.stringify(body)
  });
  return await res.json();
}

const tracksUri = [
  'spotify:track:7dyjbP9noyt8Eco6xT2eiz','spotify:track:4sDIpQ6JPxC0QLnrMBjicc','spotify:track:7fgViJ6nL1XTUklTKQhv5L','spotify:track:15P3OdV6ksFaPuS3dQgflo','spotify:track:3k91DebSBhHF4c7LeoWHSy','spotify:track:4dIhNQ6az34TPbKCeE4I27','spotify:track:2jFNCp8c72jWkuSOqo8ytI','spotify:track:5bQSOqZ8CknaHJbTCTbhmZ','spotify:track:752KAoiWV4sQFA3VaGiWpW','spotify:track:57rjpoEptJd51WyfEe3ieh'
];

async function createPlaylist(tracksUri){
  const { id: user_id } = await fetchWebApi('v1/me', 'GET')

  const playlist = await fetchWebApi(
    `v1/users/${user_id}/playlists`, 'POST', {
      "name": "My recommendation playlist",
      "description": "Playlist created by the tutorial on developer.spotify.com",
      "public": false
  })

  await fetchWebApi(
    `v1/playlists/${playlist.id}/tracks?uris=${tracksUri.join(',')}`,
    'POST'
  );

  return playlist;
}

const createdPlaylist = await createPlaylist(tracksUri);
console.log(createdPlaylist.name, createdPlaylist.id);

