#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_XY.hxx>
#include <gp_XYZ.hxx>
#include <Plate_D1.hxx>
#include <Plate_D2.hxx>
#include <Plate_D3.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <NLPlate_HGPPConstraint.hxx>
#include <NLPlate_HPG0Constraint.hxx>
#include <NLPlate_HPG0G1Constraint.hxx>
#include <NLPlate_HPG0G2Constraint.hxx>
#include <NLPlate_HPG0G3Constraint.hxx>
#include <NLPlate_HPG1Constraint.hxx>
#include <NLPlate_HPG2Constraint.hxx>
#include <NLPlate_HPG3Constraint.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_List.hxx>
#include <NLPlate_StackOfPlate.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <NLPlate_SequenceOfHGPPConstraint.hxx>
#include <Geom_Surface.hxx>
#include <NLPlate_NLPlate.hxx>

PYBIND11_MODULE(NLPlate, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Plate");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Geom");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\NLPlate_HGPPConstraint.hxx
	py::class_<NLPlate_HGPPConstraint, opencascade::handle<NLPlate_HGPPConstraint>, Standard_Transient> cls_NLPlate_HGPPConstraint(mod, "NLPlate_HGPPConstraint", "define a PinPoint geometric Constraint used to load a Non Linear Plate");
	cls_NLPlate_HGPPConstraint.def("SetUVFreeSliding", (void (NLPlate_HGPPConstraint::*)(const Standard_Boolean)) &NLPlate_HGPPConstraint::SetUVFreeSliding, "None", py::arg("UVFree"));
	cls_NLPlate_HGPPConstraint.def("SetIncrementalLoadAllowed", (void (NLPlate_HGPPConstraint::*)(const Standard_Boolean)) &NLPlate_HGPPConstraint::SetIncrementalLoadAllowed, "None", py::arg("ILA"));
	cls_NLPlate_HGPPConstraint.def("SetActiveOrder", (void (NLPlate_HGPPConstraint::*)(const Standard_Integer)) &NLPlate_HGPPConstraint::SetActiveOrder, "None", py::arg("ActiveOrder"));
	cls_NLPlate_HGPPConstraint.def("SetUV", (void (NLPlate_HGPPConstraint::*)(const gp_XY &)) &NLPlate_HGPPConstraint::SetUV, "None", py::arg("UV"));
	cls_NLPlate_HGPPConstraint.def("SetOrientation", [](NLPlate_HGPPConstraint &self) -> void { return self.SetOrientation(); });
	cls_NLPlate_HGPPConstraint.def("SetOrientation", (void (NLPlate_HGPPConstraint::*)(const Standard_Integer)) &NLPlate_HGPPConstraint::SetOrientation, "None", py::arg("Orient"));
	cls_NLPlate_HGPPConstraint.def("SetG0Criterion", (void (NLPlate_HGPPConstraint::*)(const Standard_Real)) &NLPlate_HGPPConstraint::SetG0Criterion, "None", py::arg("TolDist"));
	cls_NLPlate_HGPPConstraint.def("SetG1Criterion", (void (NLPlate_HGPPConstraint::*)(const Standard_Real)) &NLPlate_HGPPConstraint::SetG1Criterion, "None", py::arg("TolAng"));
	cls_NLPlate_HGPPConstraint.def("SetG2Criterion", (void (NLPlate_HGPPConstraint::*)(const Standard_Real)) &NLPlate_HGPPConstraint::SetG2Criterion, "None", py::arg("TolCurv"));
	cls_NLPlate_HGPPConstraint.def("SetG3Criterion", (void (NLPlate_HGPPConstraint::*)(const Standard_Real)) &NLPlate_HGPPConstraint::SetG3Criterion, "None", py::arg("TolG3"));
	cls_NLPlate_HGPPConstraint.def("UVFreeSliding", (Standard_Boolean (NLPlate_HGPPConstraint::*)() const ) &NLPlate_HGPPConstraint::UVFreeSliding, "None");
	cls_NLPlate_HGPPConstraint.def("IncrementalLoadAllowed", (Standard_Boolean (NLPlate_HGPPConstraint::*)() const ) &NLPlate_HGPPConstraint::IncrementalLoadAllowed, "None");
	cls_NLPlate_HGPPConstraint.def("ActiveOrder", (Standard_Integer (NLPlate_HGPPConstraint::*)() const ) &NLPlate_HGPPConstraint::ActiveOrder, "None");
	cls_NLPlate_HGPPConstraint.def("UV", (const gp_XY & (NLPlate_HGPPConstraint::*)() const ) &NLPlate_HGPPConstraint::UV, "None");
	cls_NLPlate_HGPPConstraint.def("Orientation", (Standard_Integer (NLPlate_HGPPConstraint::*)()) &NLPlate_HGPPConstraint::Orientation, "None");
	cls_NLPlate_HGPPConstraint.def("IsG0", (Standard_Boolean (NLPlate_HGPPConstraint::*)() const ) &NLPlate_HGPPConstraint::IsG0, "None");
	cls_NLPlate_HGPPConstraint.def("G0Target", (const gp_XYZ & (NLPlate_HGPPConstraint::*)() const ) &NLPlate_HGPPConstraint::G0Target, "None");
	cls_NLPlate_HGPPConstraint.def("G1Target", (const Plate_D1 & (NLPlate_HGPPConstraint::*)() const ) &NLPlate_HGPPConstraint::G1Target, "None");
	cls_NLPlate_HGPPConstraint.def("G2Target", (const Plate_D2 & (NLPlate_HGPPConstraint::*)() const ) &NLPlate_HGPPConstraint::G2Target, "None");
	cls_NLPlate_HGPPConstraint.def("G3Target", (const Plate_D3 & (NLPlate_HGPPConstraint::*)() const ) &NLPlate_HGPPConstraint::G3Target, "None");
	cls_NLPlate_HGPPConstraint.def("G0Criterion", (Standard_Real (NLPlate_HGPPConstraint::*)() const ) &NLPlate_HGPPConstraint::G0Criterion, "None");
	cls_NLPlate_HGPPConstraint.def("G1Criterion", (Standard_Real (NLPlate_HGPPConstraint::*)() const ) &NLPlate_HGPPConstraint::G1Criterion, "None");
	cls_NLPlate_HGPPConstraint.def("G2Criterion", (Standard_Real (NLPlate_HGPPConstraint::*)() const ) &NLPlate_HGPPConstraint::G2Criterion, "None");
	cls_NLPlate_HGPPConstraint.def("G3Criterion", (Standard_Real (NLPlate_HGPPConstraint::*)() const ) &NLPlate_HGPPConstraint::G3Criterion, "None");
	cls_NLPlate_HGPPConstraint.def_static("get_type_name_", (const char * (*)()) &NLPlate_HGPPConstraint::get_type_name, "None");
	cls_NLPlate_HGPPConstraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NLPlate_HGPPConstraint::get_type_descriptor, "None");
	cls_NLPlate_HGPPConstraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (NLPlate_HGPPConstraint::*)() const ) &NLPlate_HGPPConstraint::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NLPlate_HPG0Constraint.hxx
	py::class_<NLPlate_HPG0Constraint, opencascade::handle<NLPlate_HPG0Constraint>, NLPlate_HGPPConstraint> cls_NLPlate_HPG0Constraint(mod, "NLPlate_HPG0Constraint", "define a PinPoint G0 Constraint used to load a Non Linear Plate");
	cls_NLPlate_HPG0Constraint.def(py::init<const gp_XY &, const gp_XYZ &>(), py::arg("UV"), py::arg("Value"));
	cls_NLPlate_HPG0Constraint.def("SetUVFreeSliding", (void (NLPlate_HPG0Constraint::*)(const Standard_Boolean)) &NLPlate_HPG0Constraint::SetUVFreeSliding, "None", py::arg("UVFree"));
	cls_NLPlate_HPG0Constraint.def("SetIncrementalLoadAllowed", (void (NLPlate_HPG0Constraint::*)(const Standard_Boolean)) &NLPlate_HPG0Constraint::SetIncrementalLoadAllowed, "None", py::arg("ILA"));
	cls_NLPlate_HPG0Constraint.def("UVFreeSliding", (Standard_Boolean (NLPlate_HPG0Constraint::*)() const ) &NLPlate_HPG0Constraint::UVFreeSliding, "None");
	cls_NLPlate_HPG0Constraint.def("IncrementalLoadAllowed", (Standard_Boolean (NLPlate_HPG0Constraint::*)() const ) &NLPlate_HPG0Constraint::IncrementalLoadAllowed, "None");
	cls_NLPlate_HPG0Constraint.def("ActiveOrder", (Standard_Integer (NLPlate_HPG0Constraint::*)() const ) &NLPlate_HPG0Constraint::ActiveOrder, "None");
	cls_NLPlate_HPG0Constraint.def("IsG0", (Standard_Boolean (NLPlate_HPG0Constraint::*)() const ) &NLPlate_HPG0Constraint::IsG0, "None");
	cls_NLPlate_HPG0Constraint.def("G0Target", (const gp_XYZ & (NLPlate_HPG0Constraint::*)() const ) &NLPlate_HPG0Constraint::G0Target, "None");
	cls_NLPlate_HPG0Constraint.def_static("get_type_name_", (const char * (*)()) &NLPlate_HPG0Constraint::get_type_name, "None");
	cls_NLPlate_HPG0Constraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NLPlate_HPG0Constraint::get_type_descriptor, "None");
	cls_NLPlate_HPG0Constraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (NLPlate_HPG0Constraint::*)() const ) &NLPlate_HPG0Constraint::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NLPlate_HPG0G1Constraint.hxx
	py::class_<NLPlate_HPG0G1Constraint, opencascade::handle<NLPlate_HPG0G1Constraint>, NLPlate_HPG0Constraint> cls_NLPlate_HPG0G1Constraint(mod, "NLPlate_HPG0G1Constraint", "define a PinPoint G0+G1 Constraint used to load a Non Linear Plate");
	cls_NLPlate_HPG0G1Constraint.def(py::init<const gp_XY &, const gp_XYZ &, const Plate_D1 &>(), py::arg("UV"), py::arg("Value"), py::arg("D1T"));
	cls_NLPlate_HPG0G1Constraint.def("SetOrientation", [](NLPlate_HPG0G1Constraint &self) -> void { return self.SetOrientation(); });
	cls_NLPlate_HPG0G1Constraint.def("SetOrientation", (void (NLPlate_HPG0G1Constraint::*)(const Standard_Integer)) &NLPlate_HPG0G1Constraint::SetOrientation, "None", py::arg("Orient"));
	cls_NLPlate_HPG0G1Constraint.def("ActiveOrder", (Standard_Integer (NLPlate_HPG0G1Constraint::*)() const ) &NLPlate_HPG0G1Constraint::ActiveOrder, "None");
	cls_NLPlate_HPG0G1Constraint.def("Orientation", (Standard_Integer (NLPlate_HPG0G1Constraint::*)()) &NLPlate_HPG0G1Constraint::Orientation, "None");
	cls_NLPlate_HPG0G1Constraint.def("G1Target", (const Plate_D1 & (NLPlate_HPG0G1Constraint::*)() const ) &NLPlate_HPG0G1Constraint::G1Target, "None");
	cls_NLPlate_HPG0G1Constraint.def_static("get_type_name_", (const char * (*)()) &NLPlate_HPG0G1Constraint::get_type_name, "None");
	cls_NLPlate_HPG0G1Constraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NLPlate_HPG0G1Constraint::get_type_descriptor, "None");
	cls_NLPlate_HPG0G1Constraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (NLPlate_HPG0G1Constraint::*)() const ) &NLPlate_HPG0G1Constraint::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NLPlate_HPG0G2Constraint.hxx
	py::class_<NLPlate_HPG0G2Constraint, opencascade::handle<NLPlate_HPG0G2Constraint>, NLPlate_HPG0G1Constraint> cls_NLPlate_HPG0G2Constraint(mod, "NLPlate_HPG0G2Constraint", "define a PinPoint G0+G2 Constraint used to load a Non Linear Plate");
	cls_NLPlate_HPG0G2Constraint.def(py::init<const gp_XY &, const gp_XYZ &, const Plate_D1 &, const Plate_D2 &>(), py::arg("UV"), py::arg("Value"), py::arg("D1T"), py::arg("D2T"));
	cls_NLPlate_HPG0G2Constraint.def("ActiveOrder", (Standard_Integer (NLPlate_HPG0G2Constraint::*)() const ) &NLPlate_HPG0G2Constraint::ActiveOrder, "None");
	cls_NLPlate_HPG0G2Constraint.def("G2Target", (const Plate_D2 & (NLPlate_HPG0G2Constraint::*)() const ) &NLPlate_HPG0G2Constraint::G2Target, "None");
	cls_NLPlate_HPG0G2Constraint.def_static("get_type_name_", (const char * (*)()) &NLPlate_HPG0G2Constraint::get_type_name, "None");
	cls_NLPlate_HPG0G2Constraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NLPlate_HPG0G2Constraint::get_type_descriptor, "None");
	cls_NLPlate_HPG0G2Constraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (NLPlate_HPG0G2Constraint::*)() const ) &NLPlate_HPG0G2Constraint::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NLPlate_HPG0G3Constraint.hxx
	py::class_<NLPlate_HPG0G3Constraint, opencascade::handle<NLPlate_HPG0G3Constraint>, NLPlate_HPG0G2Constraint> cls_NLPlate_HPG0G3Constraint(mod, "NLPlate_HPG0G3Constraint", "define a PinPoint G0+G3 Constraint used to load a Non Linear Plate");
	cls_NLPlate_HPG0G3Constraint.def(py::init<const gp_XY &, const gp_XYZ &, const Plate_D1 &, const Plate_D2 &, const Plate_D3 &>(), py::arg("UV"), py::arg("Value"), py::arg("D1T"), py::arg("D2T"), py::arg("D3T"));
	cls_NLPlate_HPG0G3Constraint.def("ActiveOrder", (Standard_Integer (NLPlate_HPG0G3Constraint::*)() const ) &NLPlate_HPG0G3Constraint::ActiveOrder, "None");
	cls_NLPlate_HPG0G3Constraint.def("G3Target", (const Plate_D3 & (NLPlate_HPG0G3Constraint::*)() const ) &NLPlate_HPG0G3Constraint::G3Target, "None");
	cls_NLPlate_HPG0G3Constraint.def_static("get_type_name_", (const char * (*)()) &NLPlate_HPG0G3Constraint::get_type_name, "None");
	cls_NLPlate_HPG0G3Constraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NLPlate_HPG0G3Constraint::get_type_descriptor, "None");
	cls_NLPlate_HPG0G3Constraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (NLPlate_HPG0G3Constraint::*)() const ) &NLPlate_HPG0G3Constraint::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NLPlate_HPG1Constraint.hxx
	py::class_<NLPlate_HPG1Constraint, opencascade::handle<NLPlate_HPG1Constraint>, NLPlate_HGPPConstraint> cls_NLPlate_HPG1Constraint(mod, "NLPlate_HPG1Constraint", "define a PinPoint (no G0) G1 Constraint used to load a Non Linear Plate");
	cls_NLPlate_HPG1Constraint.def(py::init<const gp_XY &, const Plate_D1 &>(), py::arg("UV"), py::arg("D1T"));
	cls_NLPlate_HPG1Constraint.def("SetIncrementalLoadAllowed", (void (NLPlate_HPG1Constraint::*)(const Standard_Boolean)) &NLPlate_HPG1Constraint::SetIncrementalLoadAllowed, "None", py::arg("ILA"));
	cls_NLPlate_HPG1Constraint.def("SetOrientation", [](NLPlate_HPG1Constraint &self) -> void { return self.SetOrientation(); });
	cls_NLPlate_HPG1Constraint.def("SetOrientation", (void (NLPlate_HPG1Constraint::*)(const Standard_Integer)) &NLPlate_HPG1Constraint::SetOrientation, "None", py::arg("Orient"));
	cls_NLPlate_HPG1Constraint.def("IncrementalLoadAllowed", (Standard_Boolean (NLPlate_HPG1Constraint::*)() const ) &NLPlate_HPG1Constraint::IncrementalLoadAllowed, "None");
	cls_NLPlate_HPG1Constraint.def("ActiveOrder", (Standard_Integer (NLPlate_HPG1Constraint::*)() const ) &NLPlate_HPG1Constraint::ActiveOrder, "None");
	cls_NLPlate_HPG1Constraint.def("IsG0", (Standard_Boolean (NLPlate_HPG1Constraint::*)() const ) &NLPlate_HPG1Constraint::IsG0, "None");
	cls_NLPlate_HPG1Constraint.def("Orientation", (Standard_Integer (NLPlate_HPG1Constraint::*)()) &NLPlate_HPG1Constraint::Orientation, "None");
	cls_NLPlate_HPG1Constraint.def("G1Target", (const Plate_D1 & (NLPlate_HPG1Constraint::*)() const ) &NLPlate_HPG1Constraint::G1Target, "None");
	cls_NLPlate_HPG1Constraint.def_static("get_type_name_", (const char * (*)()) &NLPlate_HPG1Constraint::get_type_name, "None");
	cls_NLPlate_HPG1Constraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NLPlate_HPG1Constraint::get_type_descriptor, "None");
	cls_NLPlate_HPG1Constraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (NLPlate_HPG1Constraint::*)() const ) &NLPlate_HPG1Constraint::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NLPlate_HPG2Constraint.hxx
	py::class_<NLPlate_HPG2Constraint, opencascade::handle<NLPlate_HPG2Constraint>, NLPlate_HPG1Constraint> cls_NLPlate_HPG2Constraint(mod, "NLPlate_HPG2Constraint", "define a PinPoint (no G0) G2 Constraint used to load a Non Linear Plate");
	cls_NLPlate_HPG2Constraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D2 &>(), py::arg("UV"), py::arg("D1T"), py::arg("D2T"));
	cls_NLPlate_HPG2Constraint.def("ActiveOrder", (Standard_Integer (NLPlate_HPG2Constraint::*)() const ) &NLPlate_HPG2Constraint::ActiveOrder, "None");
	cls_NLPlate_HPG2Constraint.def("G2Target", (const Plate_D2 & (NLPlate_HPG2Constraint::*)() const ) &NLPlate_HPG2Constraint::G2Target, "None");
	cls_NLPlate_HPG2Constraint.def_static("get_type_name_", (const char * (*)()) &NLPlate_HPG2Constraint::get_type_name, "None");
	cls_NLPlate_HPG2Constraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NLPlate_HPG2Constraint::get_type_descriptor, "None");
	cls_NLPlate_HPG2Constraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (NLPlate_HPG2Constraint::*)() const ) &NLPlate_HPG2Constraint::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NLPlate_HPG3Constraint.hxx
	py::class_<NLPlate_HPG3Constraint, opencascade::handle<NLPlate_HPG3Constraint>, NLPlate_HPG2Constraint> cls_NLPlate_HPG3Constraint(mod, "NLPlate_HPG3Constraint", "define a PinPoint (no G0) G3 Constraint used to load a Non Linear Plate");
	cls_NLPlate_HPG3Constraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D2 &, const Plate_D3 &>(), py::arg("UV"), py::arg("D1T"), py::arg("D2T"), py::arg("D3T"));
	cls_NLPlate_HPG3Constraint.def("ActiveOrder", (Standard_Integer (NLPlate_HPG3Constraint::*)() const ) &NLPlate_HPG3Constraint::ActiveOrder, "None");
	cls_NLPlate_HPG3Constraint.def("G3Target", (const Plate_D3 & (NLPlate_HPG3Constraint::*)() const ) &NLPlate_HPG3Constraint::G3Target, "None");
	cls_NLPlate_HPG3Constraint.def_static("get_type_name_", (const char * (*)()) &NLPlate_HPG3Constraint::get_type_name, "None");
	cls_NLPlate_HPG3Constraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NLPlate_HPG3Constraint::get_type_descriptor, "None");
	cls_NLPlate_HPG3Constraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (NLPlate_HPG3Constraint::*)() const ) &NLPlate_HPG3Constraint::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NLPlate_NLPlate.hxx
	py::class_<NLPlate_NLPlate, std::unique_ptr<NLPlate_NLPlate, Deleter<NLPlate_NLPlate>>> cls_NLPlate_NLPlate(mod, "NLPlate_NLPlate", "None");
	cls_NLPlate_NLPlate.def(py::init<const opencascade::handle<Geom_Surface> &>(), py::arg("InitialSurface"));
	cls_NLPlate_NLPlate.def("Load", (void (NLPlate_NLPlate::*)(const opencascade::handle<NLPlate_HGPPConstraint> &)) &NLPlate_NLPlate::Load, "None", py::arg("GConst"));
	cls_NLPlate_NLPlate.def("Solve", [](NLPlate_NLPlate &self) -> void { return self.Solve(); });
	cls_NLPlate_NLPlate.def("Solve", [](NLPlate_NLPlate &self, const Standard_Integer a0) -> void { return self.Solve(a0); }, py::arg("ord"));
	cls_NLPlate_NLPlate.def("Solve", (void (NLPlate_NLPlate::*)(const Standard_Integer, const Standard_Integer)) &NLPlate_NLPlate::Solve, "None", py::arg("ord"), py::arg("InitialConsraintOrder"));
	cls_NLPlate_NLPlate.def("Solve2", [](NLPlate_NLPlate &self) -> void { return self.Solve2(); });
	cls_NLPlate_NLPlate.def("Solve2", [](NLPlate_NLPlate &self, const Standard_Integer a0) -> void { return self.Solve2(a0); }, py::arg("ord"));
	cls_NLPlate_NLPlate.def("Solve2", (void (NLPlate_NLPlate::*)(const Standard_Integer, const Standard_Integer)) &NLPlate_NLPlate::Solve2, "None", py::arg("ord"), py::arg("InitialConsraintOrder"));
	cls_NLPlate_NLPlate.def("IncrementalSolve", [](NLPlate_NLPlate &self) -> void { return self.IncrementalSolve(); });
	cls_NLPlate_NLPlate.def("IncrementalSolve", [](NLPlate_NLPlate &self, const Standard_Integer a0) -> void { return self.IncrementalSolve(a0); }, py::arg("ord"));
	cls_NLPlate_NLPlate.def("IncrementalSolve", [](NLPlate_NLPlate &self, const Standard_Integer a0, const Standard_Integer a1) -> void { return self.IncrementalSolve(a0, a1); }, py::arg("ord"), py::arg("InitialConsraintOrder"));
	cls_NLPlate_NLPlate.def("IncrementalSolve", [](NLPlate_NLPlate &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Integer a2) -> void { return self.IncrementalSolve(a0, a1, a2); }, py::arg("ord"), py::arg("InitialConsraintOrder"), py::arg("NbIncrements"));
	cls_NLPlate_NLPlate.def("IncrementalSolve", (void (NLPlate_NLPlate::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &NLPlate_NLPlate::IncrementalSolve, "None", py::arg("ord"), py::arg("InitialConsraintOrder"), py::arg("NbIncrements"), py::arg("UVSliding"));
	cls_NLPlate_NLPlate.def("IsDone", (Standard_Boolean (NLPlate_NLPlate::*)() const ) &NLPlate_NLPlate::IsDone, "returns True if all has been correctly done.");
	cls_NLPlate_NLPlate.def("destroy", (void (NLPlate_NLPlate::*)()) &NLPlate_NLPlate::destroy, "None");
	cls_NLPlate_NLPlate.def("Init", (void (NLPlate_NLPlate::*)()) &NLPlate_NLPlate::Init, "reset the Plate in the initial state ( same as after Create((Surface))");
	cls_NLPlate_NLPlate.def("Evaluate", (gp_XYZ (NLPlate_NLPlate::*)(const gp_XY &) const ) &NLPlate_NLPlate::Evaluate, "None", py::arg("point2d"));
	cls_NLPlate_NLPlate.def("EvaluateDerivative", (gp_XYZ (NLPlate_NLPlate::*)(const gp_XY &, const Standard_Integer, const Standard_Integer) const ) &NLPlate_NLPlate::EvaluateDerivative, "None", py::arg("point2d"), py::arg("iu"), py::arg("iv"));
	cls_NLPlate_NLPlate.def("Continuity", (Standard_Integer (NLPlate_NLPlate::*)() const ) &NLPlate_NLPlate::Continuity, "None");
	cls_NLPlate_NLPlate.def("ConstraintsSliding", [](NLPlate_NLPlate &self) -> void { return self.ConstraintsSliding(); });
	cls_NLPlate_NLPlate.def("ConstraintsSliding", (void (NLPlate_NLPlate::*)(const Standard_Integer)) &NLPlate_NLPlate::ConstraintsSliding, "None", py::arg("NbIterations"));
	cls_NLPlate_NLPlate.def("MaxActiveConstraintOrder", (Standard_Integer (NLPlate_NLPlate::*)() const ) &NLPlate_NLPlate::MaxActiveConstraintOrder, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<NLPlate_StackOfPlate, std::unique_ptr<NLPlate_StackOfPlate, Deleter<NLPlate_StackOfPlate>>, NCollection_BaseList> cls_NLPlate_StackOfPlate(mod, "NLPlate_StackOfPlate", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_NLPlate_StackOfPlate.def(py::init<>());
	cls_NLPlate_StackOfPlate.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_NLPlate_StackOfPlate.def(py::init([] (const NLPlate_StackOfPlate &other) {return new NLPlate_StackOfPlate(other);}), "Copy constructor", py::arg("other"));
	cls_NLPlate_StackOfPlate.def("begin", (NLPlate_StackOfPlate::iterator (NLPlate_StackOfPlate::*)() const ) &NLPlate_StackOfPlate::begin, "Returns an iterator pointing to the first element in the list.");
	cls_NLPlate_StackOfPlate.def("end", (NLPlate_StackOfPlate::iterator (NLPlate_StackOfPlate::*)() const ) &NLPlate_StackOfPlate::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_NLPlate_StackOfPlate.def("cbegin", (NLPlate_StackOfPlate::const_iterator (NLPlate_StackOfPlate::*)() const ) &NLPlate_StackOfPlate::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_NLPlate_StackOfPlate.def("cend", (NLPlate_StackOfPlate::const_iterator (NLPlate_StackOfPlate::*)() const ) &NLPlate_StackOfPlate::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_NLPlate_StackOfPlate.def("Size", (Standard_Integer (NLPlate_StackOfPlate::*)() const ) &NLPlate_StackOfPlate::Size, "Size - Number of items");
	cls_NLPlate_StackOfPlate.def("Assign", (NLPlate_StackOfPlate & (NLPlate_StackOfPlate::*)(const NLPlate_StackOfPlate &)) &NLPlate_StackOfPlate::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_NLPlate_StackOfPlate.def("assign", (NLPlate_StackOfPlate & (NLPlate_StackOfPlate::*)(const NLPlate_StackOfPlate &)) &NLPlate_StackOfPlate::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_NLPlate_StackOfPlate.def("Clear", [](NLPlate_StackOfPlate &self) -> void { return self.Clear(); });
	cls_NLPlate_StackOfPlate.def("Clear", (void (NLPlate_StackOfPlate::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &NLPlate_StackOfPlate::Clear, "Clear this list", py::arg("theAllocator"));
	cls_NLPlate_StackOfPlate.def("First", (const Plate_Plate & (NLPlate_StackOfPlate::*)() const ) &NLPlate_StackOfPlate::First, "First item");
	cls_NLPlate_StackOfPlate.def("First", (Plate_Plate & (NLPlate_StackOfPlate::*)()) &NLPlate_StackOfPlate::First, "First item (non-const)");
	cls_NLPlate_StackOfPlate.def("Last", (const Plate_Plate & (NLPlate_StackOfPlate::*)() const ) &NLPlate_StackOfPlate::Last, "Last item");
	cls_NLPlate_StackOfPlate.def("Last", (Plate_Plate & (NLPlate_StackOfPlate::*)()) &NLPlate_StackOfPlate::Last, "Last item (non-const)");
	cls_NLPlate_StackOfPlate.def("Append", (Plate_Plate & (NLPlate_StackOfPlate::*)(const Plate_Plate &)) &NLPlate_StackOfPlate::Append, "Append one item at the end", py::arg("theItem"));
	cls_NLPlate_StackOfPlate.def("Append", (void (NLPlate_StackOfPlate::*)(const Plate_Plate &, NLPlate_StackOfPlate::Iterator &)) &NLPlate_StackOfPlate::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_NLPlate_StackOfPlate.def("Append", (void (NLPlate_StackOfPlate::*)(NLPlate_StackOfPlate &)) &NLPlate_StackOfPlate::Append, "Append another list at the end", py::arg("theOther"));
	cls_NLPlate_StackOfPlate.def("Prepend", (Plate_Plate & (NLPlate_StackOfPlate::*)(const Plate_Plate &)) &NLPlate_StackOfPlate::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_NLPlate_StackOfPlate.def("Prepend", (void (NLPlate_StackOfPlate::*)(NLPlate_StackOfPlate &)) &NLPlate_StackOfPlate::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_NLPlate_StackOfPlate.def("RemoveFirst", (void (NLPlate_StackOfPlate::*)()) &NLPlate_StackOfPlate::RemoveFirst, "RemoveFirst item");
	cls_NLPlate_StackOfPlate.def("Remove", (void (NLPlate_StackOfPlate::*)(NLPlate_StackOfPlate::Iterator &)) &NLPlate_StackOfPlate::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_NLPlate_StackOfPlate.def("InsertBefore", (Plate_Plate & (NLPlate_StackOfPlate::*)(const Plate_Plate &, NLPlate_StackOfPlate::Iterator &)) &NLPlate_StackOfPlate::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_NLPlate_StackOfPlate.def("InsertBefore", (void (NLPlate_StackOfPlate::*)(NLPlate_StackOfPlate &, NLPlate_StackOfPlate::Iterator &)) &NLPlate_StackOfPlate::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_NLPlate_StackOfPlate.def("InsertAfter", (Plate_Plate & (NLPlate_StackOfPlate::*)(const Plate_Plate &, NLPlate_StackOfPlate::Iterator &)) &NLPlate_StackOfPlate::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_NLPlate_StackOfPlate.def("InsertAfter", (void (NLPlate_StackOfPlate::*)(NLPlate_StackOfPlate &, NLPlate_StackOfPlate::Iterator &)) &NLPlate_StackOfPlate::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_NLPlate_StackOfPlate.def("Reverse", (void (NLPlate_StackOfPlate::*)()) &NLPlate_StackOfPlate::Reverse, "Reverse the list");
	cls_NLPlate_StackOfPlate.def("__iter__", [](const NLPlate_StackOfPlate &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<NLPlate_ListIteratorOfStackOfPlate, std::unique_ptr<NLPlate_ListIteratorOfStackOfPlate, Deleter<NLPlate_ListIteratorOfStackOfPlate>>> cls_NLPlate_ListIteratorOfStackOfPlate(mod, "NLPlate_ListIteratorOfStackOfPlate", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_NLPlate_ListIteratorOfStackOfPlate.def(py::init<>());
	cls_NLPlate_ListIteratorOfStackOfPlate.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_NLPlate_ListIteratorOfStackOfPlate.def("More", (Standard_Boolean (NLPlate_ListIteratorOfStackOfPlate::*)() const ) &NLPlate_ListIteratorOfStackOfPlate::More, "Check end");
	cls_NLPlate_ListIteratorOfStackOfPlate.def("Next", (void (NLPlate_ListIteratorOfStackOfPlate::*)()) &NLPlate_ListIteratorOfStackOfPlate::Next, "Make step");
	cls_NLPlate_ListIteratorOfStackOfPlate.def("Value", (const Plate_Plate & (NLPlate_ListIteratorOfStackOfPlate::*)() const ) &NLPlate_ListIteratorOfStackOfPlate::Value, "Constant Value access");
	cls_NLPlate_ListIteratorOfStackOfPlate.def("Value", (Plate_Plate & (NLPlate_ListIteratorOfStackOfPlate::*)()) &NLPlate_ListIteratorOfStackOfPlate::Value, "Non-const Value access");
	cls_NLPlate_ListIteratorOfStackOfPlate.def("ChangeValue", (Plate_Plate & (NLPlate_ListIteratorOfStackOfPlate::*)() const ) &NLPlate_ListIteratorOfStackOfPlate::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<NLPlate_SequenceOfHGPPConstraint, std::unique_ptr<NLPlate_SequenceOfHGPPConstraint, Deleter<NLPlate_SequenceOfHGPPConstraint>>, NCollection_BaseSequence> cls_NLPlate_SequenceOfHGPPConstraint(mod, "NLPlate_SequenceOfHGPPConstraint", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_NLPlate_SequenceOfHGPPConstraint.def(py::init<>());
	cls_NLPlate_SequenceOfHGPPConstraint.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_NLPlate_SequenceOfHGPPConstraint.def(py::init([] (const NLPlate_SequenceOfHGPPConstraint &other) {return new NLPlate_SequenceOfHGPPConstraint(other);}), "Copy constructor", py::arg("other"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("begin", (NLPlate_SequenceOfHGPPConstraint::iterator (NLPlate_SequenceOfHGPPConstraint::*)() const ) &NLPlate_SequenceOfHGPPConstraint::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_NLPlate_SequenceOfHGPPConstraint.def("end", (NLPlate_SequenceOfHGPPConstraint::iterator (NLPlate_SequenceOfHGPPConstraint::*)() const ) &NLPlate_SequenceOfHGPPConstraint::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_NLPlate_SequenceOfHGPPConstraint.def("cbegin", (NLPlate_SequenceOfHGPPConstraint::const_iterator (NLPlate_SequenceOfHGPPConstraint::*)() const ) &NLPlate_SequenceOfHGPPConstraint::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_NLPlate_SequenceOfHGPPConstraint.def("cend", (NLPlate_SequenceOfHGPPConstraint::const_iterator (NLPlate_SequenceOfHGPPConstraint::*)() const ) &NLPlate_SequenceOfHGPPConstraint::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_NLPlate_SequenceOfHGPPConstraint.def("Size", (Standard_Integer (NLPlate_SequenceOfHGPPConstraint::*)() const ) &NLPlate_SequenceOfHGPPConstraint::Size, "Number of items");
	cls_NLPlate_SequenceOfHGPPConstraint.def("Length", (Standard_Integer (NLPlate_SequenceOfHGPPConstraint::*)() const ) &NLPlate_SequenceOfHGPPConstraint::Length, "Number of items");
	cls_NLPlate_SequenceOfHGPPConstraint.def("Lower", (Standard_Integer (NLPlate_SequenceOfHGPPConstraint::*)() const ) &NLPlate_SequenceOfHGPPConstraint::Lower, "Method for consistency with other collections.");
	cls_NLPlate_SequenceOfHGPPConstraint.def("Upper", (Standard_Integer (NLPlate_SequenceOfHGPPConstraint::*)() const ) &NLPlate_SequenceOfHGPPConstraint::Upper, "Method for consistency with other collections.");
	cls_NLPlate_SequenceOfHGPPConstraint.def("IsEmpty", (Standard_Boolean (NLPlate_SequenceOfHGPPConstraint::*)() const ) &NLPlate_SequenceOfHGPPConstraint::IsEmpty, "Empty query");
	cls_NLPlate_SequenceOfHGPPConstraint.def("Reverse", (void (NLPlate_SequenceOfHGPPConstraint::*)()) &NLPlate_SequenceOfHGPPConstraint::Reverse, "Reverse sequence");
	cls_NLPlate_SequenceOfHGPPConstraint.def("Exchange", (void (NLPlate_SequenceOfHGPPConstraint::*)(const Standard_Integer, const Standard_Integer)) &NLPlate_SequenceOfHGPPConstraint::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_NLPlate_SequenceOfHGPPConstraint.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &NLPlate_SequenceOfHGPPConstraint::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("Clear", [](NLPlate_SequenceOfHGPPConstraint &self) -> void { return self.Clear(); });
	cls_NLPlate_SequenceOfHGPPConstraint.def("Clear", (void (NLPlate_SequenceOfHGPPConstraint::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &NLPlate_SequenceOfHGPPConstraint::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("Assign", (NLPlate_SequenceOfHGPPConstraint & (NLPlate_SequenceOfHGPPConstraint::*)(const NLPlate_SequenceOfHGPPConstraint &)) &NLPlate_SequenceOfHGPPConstraint::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("assign", (NLPlate_SequenceOfHGPPConstraint & (NLPlate_SequenceOfHGPPConstraint::*)(const NLPlate_SequenceOfHGPPConstraint &)) &NLPlate_SequenceOfHGPPConstraint::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("Remove", (void (NLPlate_SequenceOfHGPPConstraint::*)(NLPlate_SequenceOfHGPPConstraint::Iterator &)) &NLPlate_SequenceOfHGPPConstraint::Remove, "Remove one item", py::arg("thePosition"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("Remove", (void (NLPlate_SequenceOfHGPPConstraint::*)(const Standard_Integer)) &NLPlate_SequenceOfHGPPConstraint::Remove, "Remove one item", py::arg("theIndex"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("Remove", (void (NLPlate_SequenceOfHGPPConstraint::*)(const Standard_Integer, const Standard_Integer)) &NLPlate_SequenceOfHGPPConstraint::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("Append", (void (NLPlate_SequenceOfHGPPConstraint::*)(const opencascade::handle<NLPlate_HGPPConstraint> &)) &NLPlate_SequenceOfHGPPConstraint::Append, "Append one item", py::arg("theItem"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("Append", (void (NLPlate_SequenceOfHGPPConstraint::*)(NLPlate_SequenceOfHGPPConstraint &)) &NLPlate_SequenceOfHGPPConstraint::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("Prepend", (void (NLPlate_SequenceOfHGPPConstraint::*)(const opencascade::handle<NLPlate_HGPPConstraint> &)) &NLPlate_SequenceOfHGPPConstraint::Prepend, "Prepend one item", py::arg("theItem"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("Prepend", (void (NLPlate_SequenceOfHGPPConstraint::*)(NLPlate_SequenceOfHGPPConstraint &)) &NLPlate_SequenceOfHGPPConstraint::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("InsertBefore", (void (NLPlate_SequenceOfHGPPConstraint::*)(const Standard_Integer, const opencascade::handle<NLPlate_HGPPConstraint> &)) &NLPlate_SequenceOfHGPPConstraint::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("InsertBefore", (void (NLPlate_SequenceOfHGPPConstraint::*)(const Standard_Integer, NLPlate_SequenceOfHGPPConstraint &)) &NLPlate_SequenceOfHGPPConstraint::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("InsertAfter", (void (NLPlate_SequenceOfHGPPConstraint::*)(NLPlate_SequenceOfHGPPConstraint::Iterator &, const opencascade::handle<NLPlate_HGPPConstraint> &)) &NLPlate_SequenceOfHGPPConstraint::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("InsertAfter", (void (NLPlate_SequenceOfHGPPConstraint::*)(const Standard_Integer, NLPlate_SequenceOfHGPPConstraint &)) &NLPlate_SequenceOfHGPPConstraint::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("InsertAfter", (void (NLPlate_SequenceOfHGPPConstraint::*)(const Standard_Integer, const opencascade::handle<NLPlate_HGPPConstraint> &)) &NLPlate_SequenceOfHGPPConstraint::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("Split", (void (NLPlate_SequenceOfHGPPConstraint::*)(const Standard_Integer, NLPlate_SequenceOfHGPPConstraint &)) &NLPlate_SequenceOfHGPPConstraint::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("First", (const opencascade::handle<NLPlate_HGPPConstraint> & (NLPlate_SequenceOfHGPPConstraint::*)() const ) &NLPlate_SequenceOfHGPPConstraint::First, "First item access");
	cls_NLPlate_SequenceOfHGPPConstraint.def("ChangeFirst", (opencascade::handle<NLPlate_HGPPConstraint> & (NLPlate_SequenceOfHGPPConstraint::*)()) &NLPlate_SequenceOfHGPPConstraint::ChangeFirst, "First item access");
	cls_NLPlate_SequenceOfHGPPConstraint.def("Last", (const opencascade::handle<NLPlate_HGPPConstraint> & (NLPlate_SequenceOfHGPPConstraint::*)() const ) &NLPlate_SequenceOfHGPPConstraint::Last, "Last item access");
	cls_NLPlate_SequenceOfHGPPConstraint.def("ChangeLast", (opencascade::handle<NLPlate_HGPPConstraint> & (NLPlate_SequenceOfHGPPConstraint::*)()) &NLPlate_SequenceOfHGPPConstraint::ChangeLast, "Last item access");
	cls_NLPlate_SequenceOfHGPPConstraint.def("Value", (const opencascade::handle<NLPlate_HGPPConstraint> & (NLPlate_SequenceOfHGPPConstraint::*)(const Standard_Integer) const ) &NLPlate_SequenceOfHGPPConstraint::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("__call__", (const opencascade::handle<NLPlate_HGPPConstraint> & (NLPlate_SequenceOfHGPPConstraint::*)(const Standard_Integer) const ) &NLPlate_SequenceOfHGPPConstraint::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("ChangeValue", (opencascade::handle<NLPlate_HGPPConstraint> & (NLPlate_SequenceOfHGPPConstraint::*)(const Standard_Integer)) &NLPlate_SequenceOfHGPPConstraint::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("__call__", (opencascade::handle<NLPlate_HGPPConstraint> & (NLPlate_SequenceOfHGPPConstraint::*)(const Standard_Integer)) &NLPlate_SequenceOfHGPPConstraint::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("SetValue", (void (NLPlate_SequenceOfHGPPConstraint::*)(const Standard_Integer, const opencascade::handle<NLPlate_HGPPConstraint> &)) &NLPlate_SequenceOfHGPPConstraint::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_NLPlate_SequenceOfHGPPConstraint.def("__iter__", [](const NLPlate_SequenceOfHGPPConstraint &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
