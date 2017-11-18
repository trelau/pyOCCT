#include <pyOCCT_Common.hpp>

#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <HLRBRep_TypeOfResultingEdge.hxx>
#include <HLRAppli_ReflectLines.hxx>

PYBIND11_MODULE(HLRAppli, mod) {

	// IMPORT
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.HLRBRep");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\HLRAppli_ReflectLines.hxx
	py::class_<HLRAppli_ReflectLines, std::unique_ptr<HLRAppli_ReflectLines, Deleter<HLRAppli_ReflectLines>>> cls_HLRAppli_ReflectLines(mod, "HLRAppli_ReflectLines", "This class builds reflect lines on a shape according to the axes of view defined by user. Reflect lines are represented by edges in 3d.");
	cls_HLRAppli_ReflectLines.def(py::init<const TopoDS_Shape &>(), py::arg("aShape"));
	cls_HLRAppli_ReflectLines.def("SetAxes", (void (HLRAppli_ReflectLines::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &HLRAppli_ReflectLines::SetAxes, "Sets the normal to the plane of visualisation, the coordinates of the view point and the coordinates of the vertical direction vector.", py::arg("Nx"), py::arg("Ny"), py::arg("Nz"), py::arg("XAt"), py::arg("YAt"), py::arg("ZAt"), py::arg("XUp"), py::arg("YUp"), py::arg("ZUp"));
	cls_HLRAppli_ReflectLines.def("Perform", (void (HLRAppli_ReflectLines::*)()) &HLRAppli_ReflectLines::Perform, "None");
	cls_HLRAppli_ReflectLines.def("GetResult", (TopoDS_Shape (HLRAppli_ReflectLines::*)() const ) &HLRAppli_ReflectLines::GetResult, "returns resulting compound of reflect lines represented by edges in 3d");
	cls_HLRAppli_ReflectLines.def("GetCompoundOf3dEdges", (TopoDS_Shape (HLRAppli_ReflectLines::*)(const HLRBRep_TypeOfResultingEdge, const Standard_Boolean, const Standard_Boolean) const ) &HLRAppli_ReflectLines::GetCompoundOf3dEdges, "returns resulting compound of lines of specified type and visibility represented by edges in 3d or 2d", py::arg("type"), py::arg("visible"), py::arg("In3d"));


}
