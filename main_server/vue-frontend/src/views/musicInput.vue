<!-- This page contains the music Input page -->
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
    <std_but type = "button" @pressed-button = "saveTyped()" text = "Save" class = "flexbut"/>
    <input type="submit" value="Submit" class = "flexbut" id = "ButtonForSubmit">
  </form>   
  
  <h2>Option 2: Button Input</h2>
  
  <p>
    Push the buttons to input the corresponding note. The duration
    defaults to 1 RU.
  </p>

  <p>
      Your Input: 
  </p>

  <p class="inputdisp">{{this.script}} </p>

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


    <div class="submitButtons">
    <std_but type = "button" @pressed-button = "save()" text = "Save" class = "flexbut2"/>
    <std_but type = "button" @pressed-button = "reset()" text = "Reset" class = "flexbut2"/>
    <std_but @pressed-button = "submit()" text = "Submit" class = "flexbut2"/>
    </div>

  </form>

  <h2>Option 3: Load saved music</h2>
  
  <p>
    Type in your song ID in the box below and press load to load your song. You can 
    the press submit to submit the song to be played. 
  </p>

  
    <textarea v-model = "songID" class = "idinput">Input your music here.</textarea>
    <br/>
   
  
  <std_but type = "button" @pressed-button = "load()" text = "Load" class = "flexbut2"/>
  
  <p>Loaded song: </p>
  <p class="inputdisp">{{this.loaded}} </p>

    
  <std_but type="button" @pressed-button = 'submitLoad()' text="Submit" class = "flexbut2" id = "ButtonForSubmit"></std_but>

  
  <!-- Error/success notification elements.  -->
  <div id="snackbar">{{error}}</div>
  <div id="snackbarG">{{error}}</div>
    

</div>
</template>

<script>
import std_but from "/src/components/std_but.vue"
import axios from 'axios'

  export default{
    
    name: 'musicInput',
    data(){
        return{
            count:0,        //legacy code
            script: '',     //button input data
            typedscript:'', //typed input data
            error: '',      //Error message data (e.g. Invalid inpiut)
            songID:'',      //Stores the songID for save song
            loaded:'',      //Stores the loaded song. 
        }
    },
    components:{
      std_but,
    },
    methods:{
        //Buttons add the button content (e.g. C1) to the button input script (this.script)
        clicked(nextchar){
          this.count++
          this.script = this.script.concat(nextchar)
        },
        //sets the scripts to 0. 
        reset(){
          this.script=''
        },
        //submits the typed input (this.typedscript) to the server by HTML POST request to /api/input. Includes error checking
        async submitForm(){
          var pattern = /^(([A-GR][0-9]+)*)$/
          console.log(pattern.test(this.typedscript))

          //error checking
          if(!pattern.test(this.typedscript)){
            console.log('inputerr')
            this.showBar('Input error. Please study the input format in detail.', '')
            return
          }

          //check that robot is free before sending requests. 
          var p = this.isFree()
          console.log("checking server is free?")
          console.log(p)

          //if playing "0", notify user and reject input. 
          if (this.isFree() == 0){
            console.log('robot playing')
            this.showBar('The robot is currently playing music. Please try again later','')
            return
          }

          //if cannot connect, reject input, and notify. 
          if(this.isFree() == 2){
            this.showBar("Server error. Please try again later.",'')
            return
          }
         
         else {
            console.log('submitted, typed')
            //prepare HTML POST request with typed data. 
            const request = {
              type: 'MusicInTyped',
              arguments: this.typedscript,
            }
            
            await axios 
              .post('/api/input/', request)
              .then(response =>{
                console.log(response)

                //update cookies for total song plays. 
                window.$cookies.set("sum", (parseInt(window.$cookies.get("sum")) + 1))

                //parse and update notes, and update statistics for each note played. 
                var isLetter = /^[A-GR]$/

                for(var i = 0; i < this.typedscript.length; i++ ){
                  var letter = this.typedscript.charAt(i)
                  if(isLetter.test(letter)){
                    window.$cookies.set(letter, (parseInt(window.$cookies.get(letter)) + 1))
                  }
                }

                this.showBar("Submission accepted. You will now be redirected home", 'G')
                setTimeout(this.redirectHome, 2500)
                
              }).catch(error => {
                console.log(error.status)
                this.showBar("Server error. Please try again later.",'')
              })
          } 
        },
        //submits the button inputs so far to the server via POST request. Checks this.script
        async submitBut(){
          console.log('submitted, button')
          const request = {
            type: 'MusicInButtoned',
            arguments: this.script,
          }

          //check server is free and available. if not, block
          var p = this.isFree()
          console.log("checking server is free?")
          console.log(p)

          if (this.isFree() == 0){
            console.log('robot playing')
            this.showBar('The robot is currently playing music. Please try again later','')
            return
          }

          if(this.isFree() == 2){
            this.showBar("Server error. Please try again later.",'')
            return
          }
          
          //send HTML post request to server (/api/input) with input. checks this.typedscript. 
          await axios 
            .post('/api/input/', request)
            .then(response =>{
              console.log(response)

              var isLetter = /^[A-GR]$/

              //parse and update statistics on cookies. 
              for(var i = 0; i < this.script.length; i++ ){
                var letter = this.script.charAt(i)
                if(isLetter.test(letter)){
                  window.$cookies.set(letter, (parseInt(window.$cookies.get(letter)) + 1))
                }
              }
              
              window.$cookies.set("sum", (parseInt(window.$cookies.get("sum")) + 1))

              //notify user.
              this.showBar("Submission accepted. You will now be redirected home", 'G')
              setTimeout(this.redirectHome, 2500)
            }).catch(error => {
              //notify user. 
              console.log(error)
              this.showBar("Server error. Please try again later.",'')
            })
          },
          //code to display notification snackbar. 
          showBar(input, color) {
            this.error = input
            var x = document.getElementById("snackbar" + color);
            x.className = "show";
            setTimeout(function(){ x.className = x.className.replace("show", ""); }, 3000);
          },
          //code to redirect to homepage.  after submissions. 
          redirectHome(){
            this.$router.push('/')
          },
          //code to check that server is free by HTML (/api/status) get request. Returns 1 if free, 2 if server has error, and 0 for
          // any other status. 
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
                console.log(error.status)
                console.log("Returning false because server err")
                return 2
              })
          },
          //function to save songs to cookies. For button inputs. 
          save() {
            //gets current song quantity in cookies for ID generation size
            var curr = window.$cookies.get("songsz")
            curr++
            //sets total song quantity and saves button input so far to cookies. 
            window.$cookies.set('S' + curr, this.script)
            window.$cookies.set("songsz", curr)
            //tells user about ID
            alert("The song ID is: " + curr + ". \n You will need this ID to load the song, so keep it in a safe place")
            
          },
          //function to save songs to cookies. For typed inputs. 
          saveTyped() {
            //gets current song quantity in cookies for ID generation size
            var pattern = /^(([A-GR][0-9]+)*)$/

            //checks that user input is valid. 
            if(!pattern.test(this.typedscript)){
              console.log('inputerr')
              this.showBar('Input error. Please study the input format in detail.', '')
              return
            }
            
            //sets total song quantity and saves typed input so far to cookies. 
            var curr = window.$cookies.get("songsz")
            curr++
            window.$cookies.set('S' + curr, this.typedscript)
            window.$cookies.set("songsz", curr)
            //notify user. 
            alert("The song ID is: " + curr + ". \n You will need this ID to load the song, so keep it in a safe place")
            
          }, 
          //this function loads songs from song ID
          load(){
            //checks that input is valid, and ID does not exceed total song count (validity. )
            var pattern = /^[0-9]+$/
            var max = window.$cookies.get("songsz")

            //notify and return if not valid. 
            if(!pattern.test(this.songID) || parseInt(this.songID) > max){
              this.showBar("Song ID is invalid. Please try again.", "")
              console.log("bad load")
              return;
            }

            //load songs to this.songID.
            this.loaded = window.$cookies.get("S" + this.songID)
            this.showBar("Loaded successfully", "G")
          },
          //submits loaded content (this.load) to be played. 
          submitLoad(){
            console.log("sload")
            this.typedscript = this.loaded
            this.submitForm()
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
  .flexbut2:hover {
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
  word-wrap: break-word;
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
    width : 100%;
  }
}

.idinput{
  max-height: 40px;
  margin-top: 20px;
  margin-bottom: 20px;
}
  
</style>