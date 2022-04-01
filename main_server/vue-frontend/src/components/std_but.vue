<template>
    <button @click = "clicked()">{{text}}</button>
</template>

<script>

//A standard button that emits an event along with the button name. 

    export default{
        name: 'std_but',
        props:{
            text: String
        },
        data(){
            return{
                count:0
            }
        },
        methods:{
            clicked(){
                this.count++
                this.$emit('pressed-button', this.text.concat(1))
            }
        }
       
    }
</script>