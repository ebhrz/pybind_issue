#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include "all.h"
#include "iostream"



// #include <pybind11/stl.h>
// #include <pybind11/stl_bind.h>

// use below statements to release the GIL locker to accelerate.
// py::gil_scoped_release release;    
// py::gil_scoped_acquire acquire;
PYBIND11_MAKE_OPAQUE(std::vector<int>);


template <class T>
class srcArr{
    public:
        T* src;
        int len;
        int index;
        srcArr(T *arr,int len){
            this->src = arr;
            this->len = len;
        };
        int _len(){
            return len;
        };
        T get(int index){
            return src[index];
        };
        void set(int index,T value){
            src[index]=value;
        };
};



namespace py = pybind11;




int e[10]={1,2,3,4,5,6,7,8,9};
std::array<int,10> arr;



// void convert(){
//     vec_e.data()=std::move(e);
// }
// void convert(std::vector<int>& vec_e,int* e){
//     vec_e._M_impl._M_start = e;
// }
typedef struct
{
    int *a;
    char b;
}aaa;

typedef struct
{
  aaa a[10];
  int d[10];  
}bbb;


void changee(int i){
    arr[i]=20;
}



// void setb(aaa *a){
//     a->b = (char*)malloc(10*sizeof(char));
//     a->b[0] = 'h';
//     a->b[1] = 'e';
//     a->b[2] = '\0';
// }

// void getb(aaa& a){
//     std::cout<<*(a.b)<<std::endl;
// }

// void geta(aaa a){
//     std::cout<<a.a<<std::endl;
// }

// void getb1(char b){
//     std::cout<<b<<std::endl;
// }

// void getb2(char* b){
//     std::cout<<*b<<std::endl;
// }

void getd(bbb& b){
    std::cout<<b.d[2]<<std::endl;
}

void sete(void){
    std::move(std::begin(e),std::end(e),arr.begin());
}

int gete(int i){
    return e[i];
}

int getarre(int i){
    return arr[i];
}

PYBIND11_MODULE(libtest, m) {
    m.doc() = "rtklib python interface by pybind11"; // optional module docstring
    //m.def("uncompress",&uncompress,"test");
    // m.def("setb",&setb,"call");
    // m.def("getb",&getb,"call");
    // m.def("getb1",&getb1,"call");
    // m.def("getb2",&getb2,"call");
    // m.def("geta",&geta,"test");
    // py::bind_vector<std::vector<int>>(m, "VectorInt");
    // py::bind_vector<std::vector<aaa>>(m, "VectorAaa");
    //py::bind_vector<std::vector<int>>(m, "VectorInt");
    py::class_<srcArr<int>>(m,"srcArrInt")
        .def("__len__",[](srcArr<int> &arr){return &arr.len;})
        .def("__getitem__",[](srcArr<int> &arr,int i){return &arr.src[i];})
        .def("__setitem__",[](srcArr<int> &arr,int i, int v){arr.src[i]=v;})
        .def("__iter__",[](srcArr<int> &arr){return py::make_iterator(arr.src,arr.src+arr.len);});
    m.attr("e") = new srcArr<int>(e,10);
    m.def("getd",&getd,"test");
    m.def("changee",&changee,"test");
    m.def("sete",&sete,"sete");
    m.def("gete",&gete,"test");
    m.def("getarre",&getarre,"test");
    //m.def("convert",&convert,"test");
    // py::class_<aaa>(m,"aaa")
    //     .def(py::init())
    //     .def_readwrite("a",&aaa::a)
    //     .def_readwrite("b",&aaa::b);
    // py::class_<bbb>(m,"bbb")
    //     .def(py::init())
    //     .def_property_readonly("a",[](py::object& obj) {bbb& o = obj.cast<bbb&>(); return py::array{10, o.a, obj};})
    //     .def_property_readonly("d",[](py::object& obj) {bbb& o = obj.cast<bbb&>(); return py::array{10, o.d, obj};});
    //auto capsule = py::capsule(e, [](void *e) { delete reinterpret_cast<int*>(e); });
    // m.attr("e")=&vec_e;
    // m.attr("e")=py::array(10,e,py::capsule(e, [](void *e) {}));
    // PYBIND11_NUMPY_DTYPE(aaa, a, b);
    // PYBIND11_NUMPY_DTYPE(bbb, a, d);
    // py::class_<bbb>(m,"bbb")
    // .def(py::init())
    //     .def_property_readonly("a",[](py::object& obj) {bbb& o = obj.cast<bbb&>(); return std::vector<aaa>(o.a,o.a+10);});//py::array_t<aaa>{10, o.a, obj};})
        //.def_property_readonly("d",[](py::object& obj) {bbb& o = obj.cast<bbb&>(); return std::vector<int>(o.d,o.d+10);});//py::array_t<int>{10, o.d, obj};});
}
