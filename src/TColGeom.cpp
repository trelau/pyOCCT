#include <pyOCCT_Common.hpp>

#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <TColGeom_Array1OfSurface.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Type.hxx>
#include <TColGeom_HArray1OfSurface.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <TColGeom_SequenceOfCurve.hxx>
#include <TColGeom_Array1OfBSplineCurve.hxx>
#include <TColGeom_HArray1OfBSplineCurve.hxx>
#include <TColGeom_Array1OfBezierCurve.hxx>
#include <NCollection_Array2.hxx>
#include <TColGeom_Array2OfBezierSurface.hxx>
#include <TColGeom_SequenceOfBoundedCurve.hxx>
#include <TColGeom_HSequenceOfBoundedCurve.hxx>
#include <TColGeom_Array2OfSurface.hxx>
#include <TColGeom_HArray2OfSurface.hxx>
#include <TColGeom_HSequenceOfCurve.hxx>
#include <TColGeom_Array1OfCurve.hxx>
#include <TColGeom_HArray1OfCurve.hxx>
#include <TColGeom_HArray1OfBezierCurve.hxx>
#include <TColGeom_SequenceOfSurface.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(TColGeom, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_Array1OfSurface.hxx
	bind_NCollection_Array1<opencascade::handle<Geom_Surface> >(mod, "TColGeom_Array1OfSurface");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_Array1OfBSplineCurve.hxx
	bind_NCollection_Array1<opencascade::handle<Geom_BSplineCurve> >(mod, "TColGeom_Array1OfBSplineCurve");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_SequenceOfBoundedCurve.hxx
	bind_NCollection_Sequence<opencascade::handle<Geom_BoundedCurve> >(mod, "TColGeom_SequenceOfBoundedCurve");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_Array2OfSurface.hxx
	bind_NCollection_Array2<opencascade::handle<Geom_Surface> >(mod, "TColGeom_Array2OfSurface");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_SequenceOfCurve.hxx
	bind_NCollection_Sequence<opencascade::handle<Geom_Curve> >(mod, "TColGeom_SequenceOfCurve");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_Array1OfCurve.hxx
	bind_NCollection_Array1<opencascade::handle<Geom_Curve> >(mod, "TColGeom_Array1OfCurve");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_Array1OfBezierCurve.hxx
	bind_NCollection_Array1<opencascade::handle<Geom_BezierCurve> >(mod, "TColGeom_Array1OfBezierCurve");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_HArray1OfSurface.hxx
	py::class_<TColGeom_HArray1OfSurface, opencascade::handle<TColGeom_HArray1OfSurface>, TColGeom_Array1OfSurface, Standard_Transient> cls_TColGeom_HArray1OfSurface(mod, "TColGeom_HArray1OfSurface", "None");
	cls_TColGeom_HArray1OfSurface.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom_HArray1OfSurface.def(py::init<const Standard_Integer, const Standard_Integer, const TColGeom_Array1OfSurface::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColGeom_HArray1OfSurface.def(py::init<const TColGeom_Array1OfSurface &>(), py::arg("theOther"));
	cls_TColGeom_HArray1OfSurface.def("Array1", (const TColGeom_Array1OfSurface & (TColGeom_HArray1OfSurface::*)() const ) &TColGeom_HArray1OfSurface::Array1, "None");
	cls_TColGeom_HArray1OfSurface.def("ChangeArray1", (TColGeom_Array1OfSurface & (TColGeom_HArray1OfSurface::*)()) &TColGeom_HArray1OfSurface::ChangeArray1, "None");
	cls_TColGeom_HArray1OfSurface.def_static("get_type_name_", (const char * (*)()) &TColGeom_HArray1OfSurface::get_type_name, "None");
	cls_TColGeom_HArray1OfSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HArray1OfSurface::get_type_descriptor, "None");
	cls_TColGeom_HArray1OfSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HArray1OfSurface::*)() const ) &TColGeom_HArray1OfSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_HSequenceOfCurve.hxx
	py::class_<TColGeom_HSequenceOfCurve, opencascade::handle<TColGeom_HSequenceOfCurve>, TColGeom_SequenceOfCurve, Standard_Transient> cls_TColGeom_HSequenceOfCurve(mod, "TColGeom_HSequenceOfCurve", "None");
	cls_TColGeom_HSequenceOfCurve.def(py::init<>());
	cls_TColGeom_HSequenceOfCurve.def(py::init<const TColGeom_SequenceOfCurve &>(), py::arg("theOther"));
	cls_TColGeom_HSequenceOfCurve.def("Sequence", (const TColGeom_SequenceOfCurve & (TColGeom_HSequenceOfCurve::*)() const ) &TColGeom_HSequenceOfCurve::Sequence, "None");
	cls_TColGeom_HSequenceOfCurve.def("Append", (void (TColGeom_HSequenceOfCurve::*)(const TColGeom_SequenceOfCurve::value_type &)) &TColGeom_HSequenceOfCurve::Append, "None", py::arg("theItem"));
	cls_TColGeom_HSequenceOfCurve.def("Append", (void (TColGeom_HSequenceOfCurve::*)(TColGeom_SequenceOfCurve &)) &TColGeom_HSequenceOfCurve::Append, "None", py::arg("theSequence"));
	cls_TColGeom_HSequenceOfCurve.def("ChangeSequence", (TColGeom_SequenceOfCurve & (TColGeom_HSequenceOfCurve::*)()) &TColGeom_HSequenceOfCurve::ChangeSequence, "None");
	cls_TColGeom_HSequenceOfCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom_HSequenceOfCurve::get_type_name, "None");
	cls_TColGeom_HSequenceOfCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HSequenceOfCurve::get_type_descriptor, "None");
	cls_TColGeom_HSequenceOfCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HSequenceOfCurve::*)() const ) &TColGeom_HSequenceOfCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_HArray1OfBSplineCurve.hxx
	py::class_<TColGeom_HArray1OfBSplineCurve, opencascade::handle<TColGeom_HArray1OfBSplineCurve>, TColGeom_Array1OfBSplineCurve, Standard_Transient> cls_TColGeom_HArray1OfBSplineCurve(mod, "TColGeom_HArray1OfBSplineCurve", "None");
	cls_TColGeom_HArray1OfBSplineCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom_HArray1OfBSplineCurve.def(py::init<const Standard_Integer, const Standard_Integer, const TColGeom_Array1OfBSplineCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColGeom_HArray1OfBSplineCurve.def(py::init<const TColGeom_Array1OfBSplineCurve &>(), py::arg("theOther"));
	cls_TColGeom_HArray1OfBSplineCurve.def("Array1", (const TColGeom_Array1OfBSplineCurve & (TColGeom_HArray1OfBSplineCurve::*)() const ) &TColGeom_HArray1OfBSplineCurve::Array1, "None");
	cls_TColGeom_HArray1OfBSplineCurve.def("ChangeArray1", (TColGeom_Array1OfBSplineCurve & (TColGeom_HArray1OfBSplineCurve::*)()) &TColGeom_HArray1OfBSplineCurve::ChangeArray1, "None");
	cls_TColGeom_HArray1OfBSplineCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom_HArray1OfBSplineCurve::get_type_name, "None");
	cls_TColGeom_HArray1OfBSplineCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HArray1OfBSplineCurve::get_type_descriptor, "None");
	cls_TColGeom_HArray1OfBSplineCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HArray1OfBSplineCurve::*)() const ) &TColGeom_HArray1OfBSplineCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_HArray1OfBezierCurve.hxx
	py::class_<TColGeom_HArray1OfBezierCurve, opencascade::handle<TColGeom_HArray1OfBezierCurve>, TColGeom_Array1OfBezierCurve, Standard_Transient> cls_TColGeom_HArray1OfBezierCurve(mod, "TColGeom_HArray1OfBezierCurve", "None");
	cls_TColGeom_HArray1OfBezierCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom_HArray1OfBezierCurve.def(py::init<const Standard_Integer, const Standard_Integer, const TColGeom_Array1OfBezierCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColGeom_HArray1OfBezierCurve.def(py::init<const TColGeom_Array1OfBezierCurve &>(), py::arg("theOther"));
	cls_TColGeom_HArray1OfBezierCurve.def("Array1", (const TColGeom_Array1OfBezierCurve & (TColGeom_HArray1OfBezierCurve::*)() const ) &TColGeom_HArray1OfBezierCurve::Array1, "None");
	cls_TColGeom_HArray1OfBezierCurve.def("ChangeArray1", (TColGeom_Array1OfBezierCurve & (TColGeom_HArray1OfBezierCurve::*)()) &TColGeom_HArray1OfBezierCurve::ChangeArray1, "None");
	cls_TColGeom_HArray1OfBezierCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom_HArray1OfBezierCurve::get_type_name, "None");
	cls_TColGeom_HArray1OfBezierCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HArray1OfBezierCurve::get_type_descriptor, "None");
	cls_TColGeom_HArray1OfBezierCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HArray1OfBezierCurve::*)() const ) &TColGeom_HArray1OfBezierCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_Array2OfBezierSurface.hxx
	bind_NCollection_Array2<opencascade::handle<Geom_BezierSurface> >(mod, "TColGeom_Array2OfBezierSurface");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_HSequenceOfBoundedCurve.hxx
	py::class_<TColGeom_HSequenceOfBoundedCurve, opencascade::handle<TColGeom_HSequenceOfBoundedCurve>, TColGeom_SequenceOfBoundedCurve, Standard_Transient> cls_TColGeom_HSequenceOfBoundedCurve(mod, "TColGeom_HSequenceOfBoundedCurve", "None");
	cls_TColGeom_HSequenceOfBoundedCurve.def(py::init<>());
	cls_TColGeom_HSequenceOfBoundedCurve.def(py::init<const TColGeom_SequenceOfBoundedCurve &>(), py::arg("theOther"));
	cls_TColGeom_HSequenceOfBoundedCurve.def("Sequence", (const TColGeom_SequenceOfBoundedCurve & (TColGeom_HSequenceOfBoundedCurve::*)() const ) &TColGeom_HSequenceOfBoundedCurve::Sequence, "None");
	cls_TColGeom_HSequenceOfBoundedCurve.def("Append", (void (TColGeom_HSequenceOfBoundedCurve::*)(const TColGeom_SequenceOfBoundedCurve::value_type &)) &TColGeom_HSequenceOfBoundedCurve::Append, "None", py::arg("theItem"));
	cls_TColGeom_HSequenceOfBoundedCurve.def("Append", (void (TColGeom_HSequenceOfBoundedCurve::*)(TColGeom_SequenceOfBoundedCurve &)) &TColGeom_HSequenceOfBoundedCurve::Append, "None", py::arg("theSequence"));
	cls_TColGeom_HSequenceOfBoundedCurve.def("ChangeSequence", (TColGeom_SequenceOfBoundedCurve & (TColGeom_HSequenceOfBoundedCurve::*)()) &TColGeom_HSequenceOfBoundedCurve::ChangeSequence, "None");
	cls_TColGeom_HSequenceOfBoundedCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom_HSequenceOfBoundedCurve::get_type_name, "None");
	cls_TColGeom_HSequenceOfBoundedCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HSequenceOfBoundedCurve::get_type_descriptor, "None");
	cls_TColGeom_HSequenceOfBoundedCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HSequenceOfBoundedCurve::*)() const ) &TColGeom_HSequenceOfBoundedCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_HArray2OfSurface.hxx
	py::class_<TColGeom_HArray2OfSurface, opencascade::handle<TColGeom_HArray2OfSurface>, TColGeom_Array2OfSurface, Standard_Transient> cls_TColGeom_HArray2OfSurface(mod, "TColGeom_HArray2OfSurface", "None");
	cls_TColGeom_HArray2OfSurface.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColGeom_HArray2OfSurface.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColGeom_Array2OfSurface::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColGeom_HArray2OfSurface.def(py::init<const TColGeom_Array2OfSurface &>(), py::arg("theOther"));
	cls_TColGeom_HArray2OfSurface.def("Array2", (const TColGeom_Array2OfSurface & (TColGeom_HArray2OfSurface::*)() const ) &TColGeom_HArray2OfSurface::Array2, "None");
	cls_TColGeom_HArray2OfSurface.def("ChangeArray2", (TColGeom_Array2OfSurface & (TColGeom_HArray2OfSurface::*)()) &TColGeom_HArray2OfSurface::ChangeArray2, "None");
	cls_TColGeom_HArray2OfSurface.def_static("get_type_name_", (const char * (*)()) &TColGeom_HArray2OfSurface::get_type_name, "None");
	cls_TColGeom_HArray2OfSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HArray2OfSurface::get_type_descriptor, "None");
	cls_TColGeom_HArray2OfSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HArray2OfSurface::*)() const ) &TColGeom_HArray2OfSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_HArray1OfCurve.hxx
	py::class_<TColGeom_HArray1OfCurve, opencascade::handle<TColGeom_HArray1OfCurve>, TColGeom_Array1OfCurve, Standard_Transient> cls_TColGeom_HArray1OfCurve(mod, "TColGeom_HArray1OfCurve", "None");
	cls_TColGeom_HArray1OfCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom_HArray1OfCurve.def(py::init<const Standard_Integer, const Standard_Integer, const TColGeom_Array1OfCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColGeom_HArray1OfCurve.def(py::init<const TColGeom_Array1OfCurve &>(), py::arg("theOther"));
	cls_TColGeom_HArray1OfCurve.def("Array1", (const TColGeom_Array1OfCurve & (TColGeom_HArray1OfCurve::*)() const ) &TColGeom_HArray1OfCurve::Array1, "None");
	cls_TColGeom_HArray1OfCurve.def("ChangeArray1", (TColGeom_Array1OfCurve & (TColGeom_HArray1OfCurve::*)()) &TColGeom_HArray1OfCurve::ChangeArray1, "None");
	cls_TColGeom_HArray1OfCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom_HArray1OfCurve::get_type_name, "None");
	cls_TColGeom_HArray1OfCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HArray1OfCurve::get_type_descriptor, "None");
	cls_TColGeom_HArray1OfCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HArray1OfCurve::*)() const ) &TColGeom_HArray1OfCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_SequenceOfSurface.hxx
	bind_NCollection_Sequence<opencascade::handle<Geom_Surface> >(mod, "TColGeom_SequenceOfSurface");


}
