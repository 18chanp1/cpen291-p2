<template>
  <div class="General">
    <h1>The Music Player</h1>

    <p> Welcome to our music player. We have poured in
      our hearts and our souls into this music player, 
      we hope you will enjoy the wonderful tunes and 
      the educational musical experiences this robot.
    </p>

    <h2>Robot status</h2>
    <div id = statusIndicator class="statusYellow">
      {{this.status}}
    </div>
    <!-- <std_but type = "button" @pressed-button = "clicked($event)" class="flexbut" text = "cunt"/> -->

    <h2>Robot Mode</h2>
    <p>
      Use the toggle to select the mode of operation for the robot. 
    </p>


    <div class = "switchNLabels">
      
      <div>Device Control</div>
      <div>
        <label class="switch">
        <input @click = "submitMode()" v-model = "selector" type="checkbox">
        <span class="slider"></span>
        </label>
      </div>
      <div>Web control</div>


    </div>
    


    <h2>Music selector</h2>
    <p>Select from your choice of music here</p>
    <div class = dd>
    <drop_down>Tetis</drop_down>
    </div>

  </div>
</template>

<script>
  import axios from 'axios'
  import drop_down from '/src/components/drop_down.vue'

  // import std_but from '/src/components/std_but.vue'
  export default {
    name: 'homePage',
    data() { 
      return{
        status: 'Loading',
        selector: true,
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
        var elem = document.getElementById("statusIndicator")    
          await axios 
            .get('/api/status')
            .then(response =>{
              console.log(response)

              if(this.status == 'PLAYING'){
                elem.className = "statusGreen"
              }
              
              this.status = response.data

              
              
            }).catch(error => {
              elem.className = "statusRed"
              this.status = "Failed to fetch status of robot"
              console.log(error.status)
            })
      },
      pollStatusWrapper() {
        this.pollStatus()
        setInterval(this.pollStatus, 4000)
      },
      async submitMode(){
        console.log('submitted, typed')
            var opmode
            if(this.selector == false){
              opmode = 'online'
            }
            if(this.selector == true){
              opmode = 'arduino'
            }

            const request = {
              type: 'changeMode',
              arguments: opmode,
            }
            
            await axios 
              .post('/api/toggle/', request)
              .then(response =>{
                console.log(response)
                
              }).catch(error => {
                console.log(error.status)
                setTimeout(this.reverseSelect, 500)
              })
      },
      reverseSelect() {
        this.selector = !this.selector
      }
    },
    components:{
      drop_down,
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

  .statusGreen{
    background-color: rgb(0,112,60);
    color:white;
    border-color: grey;
  }

  .statusRed{
    background-color: rgb(227,24,55);
    color:white;
    border-color: grey;
  }

  .statusYellow{
    background-color: rgb(255,210,0);
    color:black;
    border-color: black;
    border-style: solid;
  }

  #statusIndicator{
    min-height: 50px;
    text-align: center;
    line-height: 100px; 
    font-weight: bold;
    font-size: 25px;
    border-radius: 4px;
    border-style: solid;
  }

  .dd{
    margin-bottom: 5em;
  }

   /* The switch - the box around the slider */
.switch {
  position: relative;
  display: inline-block;
  width: 60px;
  height: 34px;
}

/* Hide default HTML checkbox */
.switch input {
  opacity: 0;
  width: 0;
  height: 0;
}

/* The slider */
.slider {
  position: absolute;
  cursor: pointer;
  top: 0;
  left: 0;
  right: 0;
  bottom: 0;
  background-color: #ccc;
  -webkit-transition: .4s;
  transition: .4s;
}

.slider:before {
  position: absolute;
  content: "";
  height: 26px;
  width: 26px;
  left: 4px;
  bottom: 4px;
  background-color: white;
  -webkit-transition: .4s;
  transition: .4s;
}

input:checked + .slider {
  background-color: #2196F3;
}

input:focus + .slider {
  box-shadow: 0 0 1px #2196F3;
}

input:checked + .slider:before {
  -webkit-transform: translateX(26px);
  -ms-transform: translateX(26px);
  transform: translateX(26px);
}

/* Rounded sliders */
.slider.round {
  border-radius: 34px;
}

.slider.round:before {
  border-radius: 50%;
} 

.switchNLabels{
  display: flex;
  flex-grow: 1;
}

.switchNLabels > div {
  margin: auto;
  text-align: left;
  margin-top: 20px;
}



</style>