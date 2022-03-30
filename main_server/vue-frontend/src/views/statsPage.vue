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
        <th>Total song plays</th>
        <td>{{this.songs}}</td>
      </tr>
    </table>
  </div>
</template>

<script>
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
      this.cookiedata()
    },
    methods: {
      cookiedata(){
        this.songs = window.$cookies.get("sum")

        var max = window.$cookies.get('A');
        var maxChr = 'A';
        var totalNote = 0

        for(var i = 0; i < 26; i++){
          var chr = String.fromCharCode(65 + i);
          var curr = window.$cookies.get(chr);

          totalNote = totalNote + parseInt(curr)

          if(curr > max){
            max = curr
            maxChr = chr
          }

        }

        this.favnote = maxChr
        this.lifnote = totalNote
      }
      
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