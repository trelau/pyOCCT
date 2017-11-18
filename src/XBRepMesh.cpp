#include <pyOCCT_Common.hpp>

#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <XBRepMesh.hxx>

PYBIND11_MODULE(XBRepMesh, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopoDS");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\XBRepMesh.hxx
	py::class_<XBRepMesh, std::unique_ptr<XBRepMesh, Deleter<XBRepMesh>>> cls_XBRepMesh(mod, "XBRepMesh", "None");
	cls_XBRepMesh.def(py::init<>());
	// FIXME cls_XBRepMesh.def_static("Discret_", (Standard_Integer (*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real, BRepMesh_DiscretRoot *&)) &XBRepMesh::Discret, "None", py::arg("theShape"), py::arg("theDeflection"), py::arg("theAngle"), py::arg("theAlgo"));


}
