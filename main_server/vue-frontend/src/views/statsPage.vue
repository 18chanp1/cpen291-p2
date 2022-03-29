<template>
  <div class="General">
    <h1>Statistics</h1>
   
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
    font-family: Lato-Semibold;
    font-size: 38px;
    text-align: left;
    border-bottom: 1px solid #af3c43;
    border-bottom-color: rgb(175, 60, 67);
    border-bottom-style: solid;
    border-bottom-width: 1px;
    margin-bottom: .2em;
    margin-top: 1em;
    padding-bottom: .2em;
  }
   h2{
    font-family: Lato-SemiBold;
    font-size: 34px;
    text-align: left;
    margin-bottom: 11.5px;
    margin-top: 38px;
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
    min-width: 65vw;
    }
  
  @media only screen and (min-width: 768px) {
    th {
    min-width: 20em;
    }
  }
  


</style>