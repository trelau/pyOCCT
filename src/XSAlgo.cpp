#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <XSAlgo_ToolContainer.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <Message_ProgressIndicator.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <Transfer_TransientProcess.hxx>
#include <Transfer_FinderProcess.hxx>
#include <Standard_Type.hxx>
#include <XSAlgo_AlgoContainer.hxx>
#include <XSAlgo.hxx>
#include <XSAlgo_Caller.hxx>

PYBIND11_MODULE(XSAlgo, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.Message");
	py::module::import("OCCT.Transfer");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\XSAlgo_Caller.hxx
	py::enum_<XSAlgo_Caller>(mod, "XSAlgo_Caller", "Identifies the caller of the algorithm")
		.value("XSAlgo_DEFAULT", XSAlgo_Caller::XSAlgo_DEFAULT)
		.value("XSAlgo_IGES", XSAlgo_Caller::XSAlgo_IGES)
		.value("XSAlgo_STEP", XSAlgo_Caller::XSAlgo_STEP)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\XSAlgo_AlgoContainer.hxx
	py::class_<XSAlgo_AlgoContainer, opencascade::handle<XSAlgo_AlgoContainer>, Standard_Transient> cls_XSAlgo_AlgoContainer(mod, "XSAlgo_AlgoContainer", "None");
	cls_XSAlgo_AlgoContainer.def(py::init<>());
	cls_XSAlgo_AlgoContainer.def("SetToolContainer", (void (XSAlgo_AlgoContainer::*)(const opencascade::handle<XSAlgo_ToolContainer> &)) &XSAlgo_AlgoContainer::SetToolContainer, "Sets ToolContainer", py::arg("TC"));
	cls_XSAlgo_AlgoContainer.def("ToolContainer", (opencascade::handle<XSAlgo_ToolContainer> (XSAlgo_AlgoContainer::*)() const ) &XSAlgo_AlgoContainer::ToolContainer, "Returns ToolContainer");
	cls_XSAlgo_AlgoContainer.def("PrepareForTransfer", (void (XSAlgo_AlgoContainer::*)() const ) &XSAlgo_AlgoContainer::PrepareForTransfer, "Performs actions necessary for preparing environment for transfer. Empty in Open version.");
	cls_XSAlgo_AlgoContainer.def("ProcessShape", [](XSAlgo_AlgoContainer &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2, const Standard_CString a3, const Standard_CString a4, opencascade::handle<Standard_Transient> & a5) -> TopoDS_Shape { return self.ProcessShape(a0, a1, a2, a3, a4, a5); }, py::arg("shape"), py::arg("Prec"), py::arg("MaxTol"), py::arg("rscfile"), py::arg("seq"), py::arg("info"));
	cls_XSAlgo_AlgoContainer.def("ProcessShape", [](XSAlgo_AlgoContainer &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2, const Standard_CString a3, const Standard_CString a4, opencascade::handle<Standard_Transient> & a5, const opencascade::handle<Message_ProgressIndicator> & a6) -> TopoDS_Shape { return self.ProcessShape(a0, a1, a2, a3, a4, a5, a6); }, py::arg("shape"), py::arg("Prec"), py::arg("MaxTol"), py::arg("rscfile"), py::arg("seq"), py::arg("info"), py::arg("progress"));
	cls_XSAlgo_AlgoContainer.def("ProcessShape", (TopoDS_Shape (XSAlgo_AlgoContainer::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real, const Standard_CString, const Standard_CString, opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_ProgressIndicator> &, const Standard_Boolean) const ) &XSAlgo_AlgoContainer::ProcessShape, "Does shape processing with specified tolerances and returns resulting shape and associated information in the form of Transient. This information should be later transmitted to MergeTransferInfo in order to be recorded in the translation map", py::arg("shape"), py::arg("Prec"), py::arg("MaxTol"), py::arg("rscfile"), py::arg("seq"), py::arg("info"), py::arg("progress"), py::arg("NonManifold"));
	cls_XSAlgo_AlgoContainer.def("CheckPCurve", (Standard_Boolean (XSAlgo_AlgoContainer::*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, const Standard_Boolean) const ) &XSAlgo_AlgoContainer::CheckPCurve, "Checks quality of pcurve of the edge on the given face, and corrects it if necessary.", py::arg("edge"), py::arg("face"), py::arg("preci"), py::arg("isSeam"));
	cls_XSAlgo_AlgoContainer.def("MergeTransferInfo", [](XSAlgo_AlgoContainer &self, const opencascade::handle<Transfer_TransientProcess> & a0, const opencascade::handle<Standard_Transient> & a1) -> void { return self.MergeTransferInfo(a0, a1); }, py::arg("TP"), py::arg("info"));
	cls_XSAlgo_AlgoContainer.def("MergeTransferInfo", (void (XSAlgo_AlgoContainer::*)(const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<Standard_Transient> &, const Standard_Integer) const ) &XSAlgo_AlgoContainer::MergeTransferInfo, "None", py::arg("TP"), py::arg("info"), py::arg("startTPitem"));
	cls_XSAlgo_AlgoContainer.def("MergeTransferInfo", (void (XSAlgo_AlgoContainer::*)(const opencascade::handle<Transfer_FinderProcess> &, const opencascade::handle<Standard_Transient> &) const ) &XSAlgo_AlgoContainer::MergeTransferInfo, "Updates translation map (TP or FP) with information resulting from ShapeProcessing Parameter startTPitem can be used for optimisation, to restrict modifications to entities stored in TP starting from item startTPitem", py::arg("FP"), py::arg("info"));
	cls_XSAlgo_AlgoContainer.def_static("get_type_name_", (const char * (*)()) &XSAlgo_AlgoContainer::get_type_name, "None");
	cls_XSAlgo_AlgoContainer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XSAlgo_AlgoContainer::get_type_descriptor, "None");
	cls_XSAlgo_AlgoContainer.def("DynamicType", (const opencascade::handle<Standard_Type> & (XSAlgo_AlgoContainer::*)() const ) &XSAlgo_AlgoContainer::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XSAlgo_ToolContainer.hxx
	py::class_<XSAlgo_ToolContainer, opencascade::handle<XSAlgo_ToolContainer>, Standard_Transient> cls_XSAlgo_ToolContainer(mod, "XSAlgo_ToolContainer", "Returns tools used by AlgoContainer");
	cls_XSAlgo_ToolContainer.def(py::init<>());
	cls_XSAlgo_ToolContainer.def_static("get_type_name_", (const char * (*)()) &XSAlgo_ToolContainer::get_type_name, "None");
	cls_XSAlgo_ToolContainer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XSAlgo_ToolContainer::get_type_descriptor, "None");
	cls_XSAlgo_ToolContainer.def("DynamicType", (const opencascade::handle<Standard_Type> & (XSAlgo_ToolContainer::*)() const ) &XSAlgo_ToolContainer::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XSAlgo.hxx
	py::class_<XSAlgo, std::unique_ptr<XSAlgo, Deleter<XSAlgo>>> cls_XSAlgo(mod, "XSAlgo", "None");
	cls_XSAlgo.def(py::init<>());
	cls_XSAlgo.def_static("Init_", (void (*)()) &XSAlgo::Init, "Provides initerface to the algorithms from Shape Healing and others for XSTEP processors. Creates and initializes default AlgoContainer.");
	cls_XSAlgo.def_static("SetAlgoContainer_", (void (*)(const opencascade::handle<XSAlgo_AlgoContainer> &)) &XSAlgo::SetAlgoContainer, "Sets default AlgoContainer", py::arg("aContainer"));
	cls_XSAlgo.def_static("AlgoContainer_", (opencascade::handle<XSAlgo_AlgoContainer> (*)()) &XSAlgo::AlgoContainer, "Returns default AlgoContainer");


}
