function createCourse(tittle , age){
    return{
        tittle: tittle,
        age: age,
        enroll(){
            console.log('you are successfully enroled')
        }
    }
}

const course = createCourse('javascript', 19)

course.enroll()
console.log(course)

function product(name,price,discount,itemCode){
    this.itemName=name;
    this.price=price;
    this.discount=discount;
    this.itemCode=itemCode;
    this.discountvalue=function(discount){
        return price*discount/100
    }
}

const item = new product('apple',100000,5,'F30')
console.log(item)
// console.log(discountvalue)
class proaduct{
    constructor(itemNama,Praice,Descount,itemCoad){
        this.itemNama=itemNama;
        this.Praice=Praice;
        this.Descount=Descount;
        this.itemCoad=itemCoad;
    }
}

let Pencil=new proaduct('simCard',100,5,'F4r')
console.log(Pencil)