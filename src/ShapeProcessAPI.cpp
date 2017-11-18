#include <pyOCCT_Common.hpp>

#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ShapeProcess_ShapeContext.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <ShapeProcessAPI_ApplySequence.hxx>

PYBIND11_MODULE(ShapeProcessAPI, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.ShapeProcess");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.TopTools");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeProcessAPI_ApplySequence.hxx
	py::class_<ShapeProcessAPI_ApplySequence, std::unique_ptr<ShapeProcessAPI_ApplySequence, Deleter<ShapeProcessAPI_ApplySequence>>> cls_ShapeProcessAPI_ApplySequence(mod, "ShapeProcessAPI_ApplySequence", "Applies one of the sequence read from resource file.");
	cls_ShapeProcessAPI_ApplySequence.def(py::init<const Standard_CString>(), py::arg("rscName"));
	cls_ShapeProcessAPI_ApplySequence.def(py::init<const Standard_CString, const Standard_CString>(), py::arg("rscName"), py::arg("seqName"));
	cls_ShapeProcessAPI_ApplySequence.def("Context", (opencascade::handle<ShapeProcess_ShapeContext> & (ShapeProcessAPI_ApplySequence::*)()) &ShapeProcessAPI_ApplySequence::Context, "Returns object for managing resource file and sequence of operators.");
	cls_ShapeProcessAPI_ApplySequence.def("PrepareShape", [](ShapeProcessAPI_ApplySequence &self, const TopoDS_Shape & a0) -> TopoDS_Shape { return self.PrepareShape(a0); }, py::arg("shape"));
	cls_ShapeProcessAPI_ApplySequence.def("PrepareShape", [](ShapeProcessAPI_ApplySequence &self, const TopoDS_Shape & a0, const Standard_Boolean a1) -> TopoDS_Shape { return self.PrepareShape(a0, a1); }, py::arg("shape"), py::arg("fillmap"));
	cls_ShapeProcessAPI_ApplySequence.def("PrepareShape", (TopoDS_Shape (ShapeProcessAPI_ApplySequence::*)(const TopoDS_Shape &, const Standard_Boolean, const TopAbs_ShapeEnum)) &ShapeProcessAPI_ApplySequence::PrepareShape, "Performs sequence of operators stored in myRsc. If <fillmap> is True adds history 'shape-shape' into myMap for shape and its subshapes until level <until> (included). If <until> is TopAbs_SHAPE, all the subshapes are considered.", py::arg("shape"), py::arg("fillmap"), py::arg("until"));
	cls_ShapeProcessAPI_ApplySequence.def("ClearMap", (void (ShapeProcessAPI_ApplySequence::*)()) &ShapeProcessAPI_ApplySequence::ClearMap, "Clears myMap with accumulated history.");
	cls_ShapeProcessAPI_ApplySequence.def("Map", (const TopTools_DataMapOfShapeShape & (ShapeProcessAPI_ApplySequence::*)() const ) &ShapeProcessAPI_ApplySequence::Map, "Returns myMap with accumulated history.");
	cls_ShapeProcessAPI_ApplySequence.def("PrintPreparationResult", (void (ShapeProcessAPI_ApplySequence::*)() const ) &ShapeProcessAPI_ApplySequence::PrintPreparationResult, "Prints result of preparation onto the messenger of the context. Note that results can be accumulated from previous preparations it method ClearMap was not called before PrepareShape.");


}
