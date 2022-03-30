<template>
    <select class = "Generaldd" id="ddin" v-model="box_in">
        <option class="Generaldd" value="Mario">Mario Theme Song</option>
        <option class="Generaldd" value="RickRoll">Never gonna give you up</option>
        <option class="Generaldd" value="GoukurakuJoudo">Zheng's Select: Goukuraku Joudo</option>
    </select>
    &nbsp; &nbsp; &nbsp;
    <!-- <button @click = "clicked()">Submit</button> -->
    <std_but type = "button" @pressed-button = "clicked()" text = "Submit" class="flexbut2"/>

    <div id="snackbar">{{error}}</div>
    <div id="snackbarG">{{error}}</div>

</template>

<script>
  import axios from 'axios'
  import std_but from "/src/components/std_but.vue"
  import VueCookies from 'vue-cookies'

  export default {
    data() {
      return {
        box_in: '',
        error: '',
      }
    },
    components:{
      std_but,
    },
    methods:{
      clicked() {
        if(this.box_in == ''){
          return
        }

        this.submitBut()
      }, 
      async submitBut(){
          console.log('submitted, button')
          const request = {
            type: 'MusicSelection',
            arguments: this.box_in,
          }


          console.log("COOKIE")
          if($cookies.isKey(this.box_in)){
            $cookies.set(this.box_in, $cookies.get(this.box_in) + 1)
          } else {
            $cookies.set(this.box_in, 1)
            
          }
          
          console.log("submitting box itemss")
          if(this.isFree() == 0){
            this.showBar("Device is currently playing music, please try again later",'')
            return
          }

          if (this.isFree == 2){
            this.showBar("Cannot reach device, please try again later",'')
            return
          }


          await axios 
            .post('/api/selection/', request)
            .then(response =>{
              console.log(response)
              this.showBar("Submission accepted. You will now be redirected home", 'G')
              setTimeout(this.redirectHome, 2500)
            }).catch(error => {
              console.log(error)
              this.showBar("Server error. Please try again later.",'')
            })
      },
      isFree(){
            console.log('getting data')     
            axios 
              .get('/api/status')
              .then(response =>{
                console.log("The data")
                console.log(response.data)

                if(response.data == 'FREE'){
                  console.log("returning true")
                  return 1
                } else {
                  return 0
                }
              
              }).catch(error => {
                console.log(error)
                console.log("Returning false because server err")
                return 2
              })
      },
      showBar(input, color) {
        this.error = input
        var x = document.getElementById("snackbar" + color);
        x.className = "show";
        setTimeout(function(){ x.className = x.className.replace("show", ""); }, 3000);
      },
    }
  }
</script>

<style>
#ddin{
  width: 100%;
  margin-bottom: 15px;
  padding: 6px 12px;

  height: auto;
  max-width: 100%;
  min-height: 37px;

  display: block;

  font-size: 16px;
  font-weight: 500;
  line-height: 1.4375;
  color: #555;
  background-color: #fff;
  background-image: none;
  border: 1px solid #ccc;
  border-radius: 4px;

  box-shadow: inset 0 1px 1px rgba(0,0,0,.075);

  transition: border-color ease-in-out .15s,box-shadow ease-in-out .15s,-webkit-box-shadow ease-in-out .15s;
  

  /* box-sizing: border-box; */
}

.Generaldd{
    margin: auto;
    max-width: 55ch;
    text-align: left;
    justify-content: left;
    font-family: Noto Sans;
    font-size: 16px;
    font-weight: 400;
    text-align: left;
  }

  .flexbut2{
    font-family: Noto Sans;
    background-color: #26374a;
    color:white;
    margin: 3px;
    padding: 20px;
    font-size: 16px;
    text-align: center;
    border-radius: 4px;
    border: none;
    /* min-width: 10ch; */
    width: 100%;
    height: 70px;
  }

  #snackbar {
  border-radius: 4px;
  visibility: hidden;
  min-width: 250px;
  margin-left: -125px;
  background-color: #BB6464;
  color: #fff;
  text-align: center;
  border-radius: 2px;
  padding: 16px;
  position: fixed;
  z-index: 1;
  left: 50%;
  bottom: 30px;
  font-size: 20px;
}
#snackbarG{
  border-radius: 4px;
  visibility: hidden;
  min-width: 250px;
  margin-left: -125px;
  background-color: #88FF88;
  color: #000000;
  text-align: center;
  border-radius: 2px;
  padding: 16px;
  position: fixed;
  z-index: 1;
  left: 50%;
  bottom: 30px;
  font-size: 20px;
}
#snackbar.show {
  visibility: visible;
  -webkit-animation: fadein 0.5s, fadeout 0.5s 2.5s;
  animation: fadein 0.5s, fadeout 0.5s 2.5s;
}
#snackbarG.show {
  visibility: visible;
  -webkit-animation: fadein 0.5s, fadeout 0.5s 2.5s;
  animation: fadein 0.5s, fadeout 0.5s 2.5s;
}
@-webkit-keyframes fadein {
  from {bottom: 0; opacity: 0;} 
  to {bottom: 30px; opacity: 1;}
}
@keyframes fadein {
  from {bottom: 0; opacity: 0;}
  to {bottom: 30px; opacity: 1;}
}
@-webkit-keyframes fadeout {
  from {bottom: 30px; opacity: 1;} 
  to {bottom: 0; opacity: 0;}
}
@keyframes fadeout {
  from {bottom: 30px; opacity: 1;}
  to {bottom: 0; opacity: 0;}
}

textarea{
    height : 15em;
    width : 88vw;
  }


@media only screen and (min-width: 768px){
  textarea{
    height : 15em;
    width : 75ch;
  }
}
  
</style>
