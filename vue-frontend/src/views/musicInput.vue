<template>
<div class = "General">
  <h1>Upload Music</h1>
  <hr>

  <h2>Option 1: Text Input</h2>
  <p>
    To input your song, please prepare the following information:
    
  </p>
  <ol>
    <li>The pitch of each note (e.g. C)</li>
    <li>The length of each note (e.g. 1 relative unit)</li>
  </ol>

  <p>
    Insert information on units here

    Type in chronological order, the pitch of each note, followed by the length 
    of each note. Do not include spaces. 
  </p>

  <p>
    For example, if you wish to play the note C for 1 RU, followed by the note
    B for 2 RU, you would input the following:
  </p>

  <text_entry></text_entry> &nbsp; &nbsp;
  <std_but text = "Submit" />

  <p>
    c1b2 
  </p>
  <h2>Option 2: Button Input</h2>
  
  <p>
    Push the buttons to input the corresponding note. The duration
    defaults to 1 RU.
  </p>

  <div class="noteInput">
    <std_but @pressed-button = "clicked($event)" class="flexbut" text = "C"/>
    <std_but @pressed-button = "clicked($event)" class="flexbut" text = "D"/>
    <std_but @pressed-button = "clicked($event)" class="flexbut" text = "E"/>
    <std_but @pressed-button = "clicked($event)" class="flexbut" text = "F"/>
    <std_but @pressed-button = "clicked($event)" class="flexbut" text = "G"/>
    <std_but @pressed-button = "clicked($event)" class="flexbut" text = "A"/>
    <std_but @pressed-button = "clicked($event)" class="flexbut" text = "B"/>
    <std_but @pressed-button = "clicked($event)" class="flexbut" text = "C"/>
  </div>

  <p>
    Your Input: 
  </p>

  <p class="inputdisp">{{this.script}} </p>

  

  <div class="noteInput">
    <std_but @pressed-button = "reset()" text = "Reset" class = "flexbut"/>
    <std_but @pressed-button = "submit()" text = "Submit" class = "flexbut"/>
  </div>


 
</div>
</template>

<script>

import std_but from "/src/components/std_but.vue"
import text_entry from "/src/components/text_entry.vue"
  export default{
    
    name: 'musicInput',
    data(){
        return{
            count:0,
            script: ''
        }
    },
    components:{
      std_but,
      text_entry
    },
    methods:{
        clicked(nextchar){
          this.count++
          this.script = this.script.concat(nextchar)
        },
        reset(){
          this.script=''
        }
    }
       
    }

</script>


<style>
  h1{
    font-family: Lato;
    font: 38px;
    font-weight: bold;
    text-align: left;
    margin-bottom: 3px;
  }

  hr {
    border-top: 0.2px solid red;

  }

  h2{
    font-family: Lato;
    font: 36px;
    font-weight: bold;
    text-align: left;
  }

  p {
    font-family: Noto Sans;
    font: 20px;
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
    display: flex ;
    background-color: #9ADCFF;
    border-radius: 10px;
    margin:10px;
    padding: 30px;
    justify-content: center;
  }

  /* .noteInput > div {
    background-color: #f1f1f1;
    margin: 3px;
    padding: 20px;
    font-size: 20px;
    text-align: center;
    border-radius: 10px;
    flex-grow: 1;
  } */

  .flexbut{
    background-color: #f1f1f1;
    margin: 3px;
    padding: 20px;
    font-size: 20px;
    text-align: center;
    border-radius: 10px;
    flex-grow: 1;
  }

  .inputdisp{
    min-height: 30px;
  }

  

</style>


