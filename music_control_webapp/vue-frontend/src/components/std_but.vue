<template>
    <button @click = "clicked()">{{text}}</button>
</template>

<script>

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