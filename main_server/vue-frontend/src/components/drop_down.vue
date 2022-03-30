<template>
    <select v-model="box_in">
        <option value="Mario">Mario Theme Song</option>
        <option value="RickRoll">Never gonna give you up</option>
        <option value="GoukurakuJoudo">Zheng's Reccomendation: Goukuraku Joudo</option>
    </select>
    &nbsp; &nbsp; &nbsp;
    <button @click = "clicked()">Submit</button>

</template>

<script>
  import axios from 'axios'

  export default {
    data() {
      return {
        box_in: '',
      }
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
          
          console.log("submitting box items")

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
    }
  }
</script>