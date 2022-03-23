<template>
    <header>
        <h1>{{title}}</h1>
        <nav_but but_name = "Faggot"></nav_but>
    </header>
</template>

<script>
    import nav_but from './nav_but.vue'
    export default{
        name: 'hdr_bar',
        props: {
            title:{
                type: String,
                default: "The default",
            }
        },
        components:{
           nav_but 
        }

    }

</script>

<style scoped>
    header{
        display: flex;
        justify-content: space-between;
        align-items: center;
        margin-bottom:20px;
        
    }
</style>