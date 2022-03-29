<template>
<div class = "General">
  <h1>Music Input</h1>
  <!-- <hr> -->

  <h2>Option 1: Text Input</h2>
  <p>
    To input your song, please prepare the following information:
    
  </p>
  <ol>
    <li>The pitch of each note (e.g. C)</li>
    <li>The length of each note (e.g. 1 relative unit)</li>
  </ol>

  <p>
    Type in chronological order, the pitch of each note, followed by the relative length 
    of each note. Do not include spaces. 
  </p>

  <p>
    For example, if you wish to play the note C for 1 RU, followed by the note
    B for 2 RU, you would input the following:
  </p>

  <p>
    C1B2 
  </p>

  <form @submit.prevent="submitForm">
    <textarea v-model = "typedscript">Input your music here.</textarea>
    <br/>
    <input type="submit" value="Submit" class = "flexbut" id = "ButtonForSubmit">
  </form>   
  
  <h2>Option 2: Button Input</h2>
  
  <p>
    Push the buttons to input the corresponding note. The duration
    defaults to 1 RU.
  </p>

  <form @submit.prevent = "submitBut">
    <div class="noteInput">
      <std_but type = "button" @pressed-button = "clicked($event)" class="flexbut" text = "C"/>
      <std_but type = "button" @pressed-button = "clicked($event)" class="flexbut" text = "D"/>
      <std_but type = "button" @pressed-button = "clicked($event)" class="flexbut" text = "E"/>
      <std_but type = "button" @pressed-button = "clicked($event)" class="flexbut" text = "F"/>
      <std_but type = "button" @pressed-button = "clicked($event)" class="flexbut" text = "G"/>
      <std_but type = "button" @pressed-button = "clicked($event)" class="flexbut" text = "A"/>
      <std_but type = "button" @pressed-button = "clicked($event)" class="flexbut" text = "B"/>
      <std_but type = "button" @pressed-button = "clicked($event)" class="flexbut" text = "R"/>
    </div>

    <p>
      Your Input: 
    </p>

    <p class="inputdisp">{{this.script}} </p>

    <div class="submitButtons">
    <std_but type = "button" @pressed-button = "reset()" text = "Reset" class = "flexbut2"/>
    <std_but @pressed-button = "submit()" text = "Submit" class = "flexbut2"/>
    </div>

    <div id="snackbar">{{error}}</div>
    <div id="snackbarG">{{error}}</div>
    
  </form>

</div>
</template>

<script>
import std_but from "/src/components/std_but.vue"
import axios from 'axios'
  export default{
    
    name: 'musicInput',
    data(){
        return{
            count:0,
            script: '',
            typedscript:'',
            error: '',
        }
    },
    components:{
      std_but,
    },
    methods:{
        clicked(nextchar){
          this.count++
          this.script = this.script.concat(nextchar)
        },
        reset(){
          this.script=''
        },
        async submitForm(){
          var pattern = /^(([A-GR][1-9]+)*)$/
          console.log(pattern.test(this.typedscript))
         
         if(pattern.test(this.typedscript)){
            console.log('submitted, typed')
            const request = {
              type: 'MusicInTyped',
              arguments: this.typedscript,
            }
            
            await axios 
              .post('/api/input/', request)
              .then(response =>{
                console.log(response)
                this.showBar("Submission accepted. You will now be redirected home", 'G')
                setTimeout(this.redirectHome, 2500)
                
              }).catch(error => {
                console.log(error)
                this.showBar("Server error. Please try again later.",'')
              })
          } else {
            console.log('inputerr')
            this.showBar('Input error. Please study the input format in detail.', '')
          }
        },async submitBut(){
          console.log('submitted, button')
          const request = {
            type: 'MusicInButtoned',
            arguments: this.script,
          }
          
          await axios 
            .post('/api/input/', request)
            .then(response =>{
              console.log(response)
              this.showBar("Submission accepted. You will now be redirected home", 'G')
              setTimeout(this.redirectHome, 2500)
            }).catch(error => {
              console.log(error)
              this.showBar("Server error. Please try again later.",'')
            })
          },
          showBar(input, color) {
            this.error = input
            var x = document.getElementById("snackbar" + color);
            x.className = "show";
            setTimeout(function(){ x.className = x.className.replace("show", ""); }, 3000);
          },
          redirectHome(){
            this.$router.push('/')
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
    justify-content: center;
  }
  .noteInput{
    display: grid ;
    grid-template-columns: repeat(auto-fill,minmax(80px, 1fr));
    background-color: #ffffff;
    border-radius: 10px;
    margin:10px;
    padding: 30px;
    justify-content: center;
  }

  .submitButtons{
    display: flex ;
    background-color: #ffffff;
    border-radius: 10px;
    margin:10px;
    padding: 30px;
    justify-content: center;
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
  .flexbut2{
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


.flexbut:hover {
  background-color: #1c578a;
  outline:none;
  }
.button:active {
  background-color: #16446c;
  outline:none;
}
.inputdisp{
  min-height: 40px;
  border-style: solid;
  padding: 10px;
}
.entryBox {
  width: 205px; height: 39px
}
#ButtonForSubmit {
  margin-top: 1em;
}
/* Snackbar */
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