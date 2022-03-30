<template>
  <div class="General">
    <h1>The Music Player</h1>

    <p> Welcome to our music player. We have poured in
      our hearts and our souls into this music player, 
      we hope you will enjoy the wonderful tunes and 
      the educational musical experiences this robot.
    </p>

    <h2>Robot status</h2>
    {{this.status}}
    <std_but type = "button" @pressed-button = "clicked($event)" class="flexbut" text = "cunt"/>

    <h2>Robot Locker</h2>
    <p>
      Use the toggle to lock 
    </p>


  </div>
</template>

<script>
  import axios from 'axios'
  import std_but from '/src/components/std_but.vue'
  export default {
    name: 'homePage',
    data() { 
      return{
        status: 'no data'
      }
    }, mounted (){
      this.pollStatusWrapper()
    },
    methods: {
      clicked (){
        console.log('oi')
        this.$router.push('/about');
      },
      async pollStatus(){
        console.log('getting data')      
          await axios 
            .get('/api/status')
            .then(response =>{
              console.log(response)
              this.status = response.data
              
            }).catch(error => {
              console.log(error)
            })
      },
      pollStatusWrapper() {
        setInterval(this.pollStatus, 4000)
      },
    },
    components:{
      std_but,
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
    max-width: 55ch;
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
  
  .flexbut{
    font-family: Noto Sans;
    background-color: #26374a;
    color:white;
    margin: 3px;
    padding: 20px;
    font-size: 20px;
    text-align: center;
    border-radius: 4px;
    border: none;
  }


</style>