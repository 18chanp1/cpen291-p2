<template>
    <select v-model="box_in">
        <option value="M1">Mario</option>
        <option value="M2">Rickroll</option>
        <option value="M3">My heart will go on</option>
        <option value="M4">Epic sax guy</option>
    </select>
    &nbsp; &nbsp; &nbsp;
    <button @click = "clicked()">{{this.confirmation}}</button>
    <!-- <input type="submit"> -->

    <p>{{ box_in }}</p>

</template>

<script>
  export default {
    data() {
      return {
        box_in: '',
        confirmation: 'Send Request'
      }
    },
    methods:{
      clicked() {
        if(this.box_in != ''){
          this.confirmation = "Request sent"
        }
      }
    }
  }
</script>