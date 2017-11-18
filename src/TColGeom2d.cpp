#include <pyOCCT_Common.hpp>

#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <TColGeom2d_Array1OfCurve.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Type.hxx>
#include <TColGeom2d_HArray1OfCurve.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <TColGeom2d_SequenceOfCurve.hxx>
#include <TColGeom2d_Array1OfBSplineCurve.hxx>
#include <TColGeom2d_HArray1OfBSplineCurve.hxx>
#include <TColGeom2d_Array1OfBezierCurve.hxx>
#include <TColGeom2d_SequenceOfGeometry.hxx>
#include <TColGeom2d_SequenceOfBoundedCurve.hxx>
#include <TColGeom2d_HSequenceOfBoundedCurve.hxx>
#include <TColGeom2d_HSequenceOfCurve.hxx>
#include <TColGeom2d_HArray1OfBezierCurve.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(TColGeom2d, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom2d_Array1OfCurve.hxx
	bind_NCollection_Array1<opencascade::handle<Geom2d_Curve> >(mod, "TColGeom2d_Array1OfCurve");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom2d_Array1OfBSplineCurve.hxx
	bind_NCollection_Array1<opencascade::handle<Geom2d_BSplineCurve> >(mod, "TColGeom2d_Array1OfBSplineCurve");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom2d_SequenceOfBoundedCurve.hxx
	bind_NCollection_Sequence<opencascade::handle<Geom2d_BoundedCurve> >(mod, "TColGeom2d_SequenceOfBoundedCurve");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom2d_SequenceOfCurve.hxx
	bind_NCollection_Sequence<opencascade::handle<Geom2d_Curve> >(mod, "TColGeom2d_SequenceOfCurve");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom2d_Array1OfBezierCurve.hxx
	bind_NCollection_Array1<opencascade::handle<Geom2d_BezierCurve> >(mod, "TColGeom2d_Array1OfBezierCurve");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom2d_HArray1OfCurve.hxx
	py::class_<TColGeom2d_HArray1OfCurve, opencascade::handle<TColGeom2d_HArray1OfCurve>, TColGeom2d_Array1OfCurve, Standard_Transient> cls_TColGeom2d_HArray1OfCurve(mod, "TColGeom2d_HArray1OfCurve", "None");
	cls_TColGeom2d_HArray1OfCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom2d_HArray1OfCurve.def(py::init<const Standard_Integer, const Standard_Integer, const TColGeom2d_Array1OfCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColGeom2d_HArray1OfCurve.def(py::init<const TColGeom2d_Array1OfCurve &>(), py::arg("theOther"));
	cls_TColGeom2d_HArray1OfCurve.def("Array1", (const TColGeom2d_Array1OfCurve & (TColGeom2d_HArray1OfCurve::*)() const ) &TColGeom2d_HArray1OfCurve::Array1, "None");
	cls_TColGeom2d_HArray1OfCurve.def("ChangeArray1", (TColGeom2d_Array1OfCurve & (TColGeom2d_HArray1OfCurve::*)()) &TColGeom2d_HArray1OfCurve::ChangeArray1, "None");
	cls_TColGeom2d_HArray1OfCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom2d_HArray1OfCurve::get_type_name, "None");
	cls_TColGeom2d_HArray1OfCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom2d_HArray1OfCurve::get_type_descriptor, "None");
	cls_TColGeom2d_HArray1OfCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom2d_HArray1OfCurve::*)() const ) &TColGeom2d_HArray1OfCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom2d_HSequenceOfCurve.hxx
	py::class_<TColGeom2d_HSequenceOfCurve, opencascade::handle<TColGeom2d_HSequenceOfCurve>, TColGeom2d_SequenceOfCurve, Standard_Transient> cls_TColGeom2d_HSequenceOfCurve(mod, "TColGeom2d_HSequenceOfCurve", "None");
	cls_TColGeom2d_HSequenceOfCurve.def(py::init<>());
	cls_TColGeom2d_HSequenceOfCurve.def(py::init<const TColGeom2d_SequenceOfCurve &>(), py::arg("theOther"));
	cls_TColGeom2d_HSequenceOfCurve.def("Sequence", (const TColGeom2d_SequenceOfCurve & (TColGeom2d_HSequenceOfCurve::*)() const ) &TColGeom2d_HSequenceOfCurve::Sequence, "None");
	cls_TColGeom2d_HSequenceOfCurve.def("Append", (void (TColGeom2d_HSequenceOfCurve::*)(const TColGeom2d_SequenceOfCurve::value_type &)) &TColGeom2d_HSequenceOfCurve::Append, "None", py::arg("theItem"));
	cls_TColGeom2d_HSequenceOfCurve.def("Append", (void (TColGeom2d_HSequenceOfCurve::*)(TColGeom2d_SequenceOfCurve &)) &TColGeom2d_HSequenceOfCurve::Append, "None", py::arg("theSequence"));
	cls_TColGeom2d_HSequenceOfCurve.def("ChangeSequence", (TColGeom2d_SequenceOfCurve & (TColGeom2d_HSequenceOfCurve::*)()) &TColGeom2d_HSequenceOfCurve::ChangeSequence, "None");
	cls_TColGeom2d_HSequenceOfCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom2d_HSequenceOfCurve::get_type_name, "None");
	cls_TColGeom2d_HSequenceOfCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom2d_HSequenceOfCurve::get_type_descriptor, "None");
	cls_TColGeom2d_HSequenceOfCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom2d_HSequenceOfCurve::*)() const ) &TColGeom2d_HSequenceOfCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom2d_HArray1OfBSplineCurve.hxx
	py::class_<TColGeom2d_HArray1OfBSplineCurve, opencascade::handle<TColGeom2d_HArray1OfBSplineCurve>, TColGeom2d_Array1OfBSplineCurve, Standard_Transient> cls_TColGeom2d_HArray1OfBSplineCurve(mod, "TColGeom2d_HArray1OfBSplineCurve", "None");
	cls_TColGeom2d_HArray1OfBSplineCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom2d_HArray1OfBSplineCurve.def(py::init<const Standard_Integer, const Standard_Integer, const TColGeom2d_Array1OfBSplineCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColGeom2d_HArray1OfBSplineCurve.def(py::init<const TColGeom2d_Array1OfBSplineCurve &>(), py::arg("theOther"));
	cls_TColGeom2d_HArray1OfBSplineCurve.def("Array1", (const TColGeom2d_Array1OfBSplineCurve & (TColGeom2d_HArray1OfBSplineCurve::*)() const ) &TColGeom2d_HArray1OfBSplineCurve::Array1, "None");
	cls_TColGeom2d_HArray1OfBSplineCurve.def("ChangeArray1", (TColGeom2d_Array1OfBSplineCurve & (TColGeom2d_HArray1OfBSplineCurve::*)()) &TColGeom2d_HArray1OfBSplineCurve::ChangeArray1, "None");
	cls_TColGeom2d_HArray1OfBSplineCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom2d_HArray1OfBSplineCurve::get_type_name, "None");
	cls_TColGeom2d_HArray1OfBSplineCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom2d_HArray1OfBSplineCurve::get_type_descriptor, "None");
	cls_TColGeom2d_HArray1OfBSplineCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom2d_HArray1OfBSplineCurve::*)() const ) &TColGeom2d_HArray1OfBSplineCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom2d_HArray1OfBezierCurve.hxx
	py::class_<TColGeom2d_HArray1OfBezierCurve, opencascade::handle<TColGeom2d_HArray1OfBezierCurve>, TColGeom2d_Array1OfBezierCurve, Standard_Transient> cls_TColGeom2d_HArray1OfBezierCurve(mod, "TColGeom2d_HArray1OfBezierCurve", "None");
	cls_TColGeom2d_HArray1OfBezierCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom2d_HArray1OfBezierCurve.def(py::init<const Standard_Integer, const Standard_Integer, const TColGeom2d_Array1OfBezierCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColGeom2d_HArray1OfBezierCurve.def(py::init<const TColGeom2d_Array1OfBezierCurve &>(), py::arg("theOther"));
	cls_TColGeom2d_HArray1OfBezierCurve.def("Array1", (const TColGeom2d_Array1OfBezierCurve & (TColGeom2d_HArray1OfBezierCurve::*)() const ) &TColGeom2d_HArray1OfBezierCurve::Array1, "None");
	cls_TColGeom2d_HArray1OfBezierCurve.def("ChangeArray1", (TColGeom2d_Array1OfBezierCurve & (TColGeom2d_HArray1OfBezierCurve::*)()) &TColGeom2d_HArray1OfBezierCurve::ChangeArray1, "None");
	cls_TColGeom2d_HArray1OfBezierCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom2d_HArray1OfBezierCurve::get_type_name, "None");
	cls_TColGeom2d_HArray1OfBezierCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom2d_HArray1OfBezierCurve::get_type_descriptor, "None");
	cls_TColGeom2d_HArray1OfBezierCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom2d_HArray1OfBezierCurve::*)() const ) &TColGeom2d_HArray1OfBezierCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom2d_SequenceOfGeometry.hxx
	bind_NCollection_Sequence<opencascade::handle<Geom2d_Geometry> >(mod, "TColGeom2d_SequenceOfGeometry");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom2d_HSequenceOfBoundedCurve.hxx
	py::class_<TColGeom2d_HSequenceOfBoundedCurve, opencascade::handle<TColGeom2d_HSequenceOfBoundedCurve>, TColGeom2d_SequenceOfBoundedCurve, Standard_Transient> cls_TColGeom2d_HSequenceOfBoundedCurve(mod, "TColGeom2d_HSequenceOfBoundedCurve", "None");
	cls_TColGeom2d_HSequenceOfBoundedCurve.def(py::init<>());
	cls_TColGeom2d_HSequenceOfBoundedCurve.def(py::init<const TColGeom2d_SequenceOfBoundedCurve &>(), py::arg("theOther"));
	cls_TColGeom2d_HSequenceOfBoundedCurve.def("Sequence", (const TColGeom2d_SequenceOfBoundedCurve & (TColGeom2d_HSequenceOfBoundedCurve::*)() const ) &TColGeom2d_HSequenceOfBoundedCurve::Sequence, "None");
	cls_TColGeom2d_HSequenceOfBoundedCurve.def("Append", (void (TColGeom2d_HSequenceOfBoundedCurve::*)(const TColGeom2d_SequenceOfBoundedCurve::value_type &)) &TColGeom2d_HSequenceOfBoundedCurve::Append, "None", py::arg("theItem"));
	cls_TColGeom2d_HSequenceOfBoundedCurve.def("Append", (void (TColGeom2d_HSequenceOfBoundedCurve::*)(TColGeom2d_SequenceOfBoundedCurve &)) &TColGeom2d_HSequenceOfBoundedCurve::Append, "None", py::arg("theSequence"));
	cls_TColGeom2d_HSequenceOfBoundedCurve.def("ChangeSequence", (TColGeom2d_SequenceOfBoundedCurve & (TColGeom2d_HSequenceOfBoundedCurve::*)()) &TColGeom2d_HSequenceOfBoundedCurve::ChangeSequence, "None");
	cls_TColGeom2d_HSequenceOfBoundedCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom2d_HSequenceOfBoundedCurve::get_type_name, "None");
	cls_TColGeom2d_HSequenceOfBoundedCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom2d_HSequenceOfBoundedCurve::get_type_descriptor, "None");
	cls_TColGeom2d_HSequenceOfBoundedCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom2d_HSequenceOfBoundedCurve::*)() const ) &TColGeom2d_HSequenceOfBoundedCurve::DynamicType, "None");


}
