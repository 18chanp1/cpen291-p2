<template>
  <div class="General">
    <h1>Statistics</h1>
    <hr/>
   
    <table class = 'General'>
      <tr>
        <th>Your favorite note</th>
        <td>{{this.favnote}}</td>
      </tr>
      <tr>
        <th>Lifetime notes played</th>
        <td>{{this.lifnote}}</td>
      </tr>
      <tr>
        <th>Total song uploads</th>
        <td>{{this.songs}}</td>
      </tr>
    </table>
  </div>
</template>

<script>
  import axios from 'axios'

  export default {
    name: 'statsPage',
    data() { 
      return{
        favnote: 'No data',
        lifnote: 'No data',
        songs: 'No data',
      }
    },
    mounted(){
      this.getData()
    },
    methods: {
      async getData() {
          console.log('getting data')      
          await axios 
            .get('/api/stats')
            .then(response =>{
              console.log(response)
              this.favnote = response.favoriteNote
              this.lifnote = response.lifetimeNotes
              this.songs = response.numberOfSongs
              
            }).catch(error => {
              console.log(error)
            })
          },
      
    }
  }


</script>


<style>
 h1{
    font-family: Lato;
    font-size: 38px;
    font-weight: bold;
    text-align: left;
    margin-bottom: 3px;
  }

  hr {
    border-top: 0.2px solid red;

  }

  h2{
    font-family: Lato;
    font-size: 36px;
    font-weight: bold;
    text-align: left;
  }

  p {
    font-family: Noto Sans;
    font-size: 20px;
    font-weight: 500;
    text-align: left;
    max-width: 65ch;
  }

  ol {
    font-family: Noto Sans;
    font-size: 20px;
    font-weight: 500;
    text-align: left;
    max-width: 65ch;
  }

  .General{
    margin: auto;
    max-width: 65ch;
    text-align: left;
    justify-content: left;
    font-family: Noto Sans;
    font-size: 20px;
    font-weight: 500;
    text-align: left;
  }

  th {
    min-width: 20em;
  }


</style>