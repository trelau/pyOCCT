/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <NCollection_Array1.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <TColGeom_Array1OfSurface.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Std.hxx>
#include <TColGeom_HArray1OfSurface.hxx>
#include <Standard_Type.hxx>
#include <NCollection_Sequence.hxx>
#include <Geom_Curve.hxx>
#include <TColGeom_SequenceOfCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <TColGeom_Array1OfBSplineCurve.hxx>
#include <TColGeom_HArray1OfBSplineCurve.hxx>
#include <Geom_BezierCurve.hxx>
#include <TColGeom_Array1OfBezierCurve.hxx>
#include <NCollection_Array2.hxx>
#include <Geom_BezierSurface.hxx>
#include <TColGeom_Array2OfBezierSurface.hxx>
#include <Geom_BoundedCurve.hxx>
#include <TColGeom_SequenceOfBoundedCurve.hxx>
#include <TColGeom_HSequenceOfBoundedCurve.hxx>
#include <TColGeom_Array2OfSurface.hxx>
#include <TColGeom_HArray2OfSurface.hxx>
#include <TColGeom_HSequenceOfCurve.hxx>
#include <TColGeom_Array1OfCurve.hxx>
#include <TColGeom_HArray1OfCurve.hxx>
#include <TColGeom_HArray1OfBezierCurve.hxx>
#include <TColGeom_SequenceOfSurface.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_NCollection_Array2.hxx>

PYBIND11_MODULE(TColGeom, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom");

// TYPEDEF: TCOLGEOM_ARRAY1OFSURFACE
bind_NCollection_Array1<opencascade::handle<Geom_Surface> >(mod, "TColGeom_Array1OfSurface", py::module_local(false));

// CLASS: TCOLGEOM_HARRAY1OFSURFACE
py::class_<TColGeom_HArray1OfSurface, opencascade::handle<TColGeom_HArray1OfSurface>, Standard_Transient> cls_TColGeom_HArray1OfSurface(mod, "TColGeom_HArray1OfSurface", "None", py::multiple_inheritance());

// Constructors
cls_TColGeom_HArray1OfSurface.def(py::init<>());
cls_TColGeom_HArray1OfSurface.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TColGeom_HArray1OfSurface.def(py::init<const Standard_Integer, const Standard_Integer, const TColGeom_Array1OfSurface::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TColGeom_HArray1OfSurface.def(py::init<const TColGeom_Array1OfSurface &>(), py::arg("theOther"));

// Methods
// cls_TColGeom_HArray1OfSurface.def_static("operator new_", (void * (*)(size_t)) &TColGeom_HArray1OfSurface::operator new, "None", py::arg("theSize"));
// cls_TColGeom_HArray1OfSurface.def_static("operator delete_", (void (*)(void *)) &TColGeom_HArray1OfSurface::operator delete, "None", py::arg("theAddress"));
// cls_TColGeom_HArray1OfSurface.def_static("operator new[]_", (void * (*)(size_t)) &TColGeom_HArray1OfSurface::operator new[], "None", py::arg("theSize"));
// cls_TColGeom_HArray1OfSurface.def_static("operator delete[]_", (void (*)(void *)) &TColGeom_HArray1OfSurface::operator delete[], "None", py::arg("theAddress"));
// cls_TColGeom_HArray1OfSurface.def_static("operator new_", (void * (*)(size_t, void *)) &TColGeom_HArray1OfSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColGeom_HArray1OfSurface.def_static("operator delete_", (void (*)(void *, void *)) &TColGeom_HArray1OfSurface::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColGeom_HArray1OfSurface.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_HArray1OfSurface::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColGeom_HArray1OfSurface.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_HArray1OfSurface::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColGeom_HArray1OfSurface.def("Array1", (const TColGeom_Array1OfSurface & (TColGeom_HArray1OfSurface::*)() const) &TColGeom_HArray1OfSurface::Array1, "None");
cls_TColGeom_HArray1OfSurface.def("ChangeArray1", (TColGeom_Array1OfSurface & (TColGeom_HArray1OfSurface::*)()) &TColGeom_HArray1OfSurface::ChangeArray1, "None");
cls_TColGeom_HArray1OfSurface.def_static("get_type_name_", (const char * (*)()) &TColGeom_HArray1OfSurface::get_type_name, "None");
cls_TColGeom_HArray1OfSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HArray1OfSurface::get_type_descriptor, "None");
cls_TColGeom_HArray1OfSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HArray1OfSurface::*)() const) &TColGeom_HArray1OfSurface::DynamicType, "None");

// TYPEDEF: TCOLGEOM_SEQUENCEOFCURVE
bind_NCollection_Sequence<opencascade::handle<Geom_Curve> >(mod, "TColGeom_SequenceOfCurve", py::module_local(false));

// TYPEDEF: TCOLGEOM_ARRAY1OFBSPLINECURVE
bind_NCollection_Array1<opencascade::handle<Geom_BSplineCurve> >(mod, "TColGeom_Array1OfBSplineCurve", py::module_local(false));

// CLASS: TCOLGEOM_HARRAY1OFBSPLINECURVE
py::class_<TColGeom_HArray1OfBSplineCurve, opencascade::handle<TColGeom_HArray1OfBSplineCurve>, Standard_Transient> cls_TColGeom_HArray1OfBSplineCurve(mod, "TColGeom_HArray1OfBSplineCurve", "None", py::multiple_inheritance());

// Constructors
cls_TColGeom_HArray1OfBSplineCurve.def(py::init<>());
cls_TColGeom_HArray1OfBSplineCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TColGeom_HArray1OfBSplineCurve.def(py::init<const Standard_Integer, const Standard_Integer, const TColGeom_Array1OfBSplineCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TColGeom_HArray1OfBSplineCurve.def(py::init<const TColGeom_Array1OfBSplineCurve &>(), py::arg("theOther"));

// Methods
// cls_TColGeom_HArray1OfBSplineCurve.def_static("operator new_", (void * (*)(size_t)) &TColGeom_HArray1OfBSplineCurve::operator new, "None", py::arg("theSize"));
// cls_TColGeom_HArray1OfBSplineCurve.def_static("operator delete_", (void (*)(void *)) &TColGeom_HArray1OfBSplineCurve::operator delete, "None", py::arg("theAddress"));
// cls_TColGeom_HArray1OfBSplineCurve.def_static("operator new[]_", (void * (*)(size_t)) &TColGeom_HArray1OfBSplineCurve::operator new[], "None", py::arg("theSize"));
// cls_TColGeom_HArray1OfBSplineCurve.def_static("operator delete[]_", (void (*)(void *)) &TColGeom_HArray1OfBSplineCurve::operator delete[], "None", py::arg("theAddress"));
// cls_TColGeom_HArray1OfBSplineCurve.def_static("operator new_", (void * (*)(size_t, void *)) &TColGeom_HArray1OfBSplineCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColGeom_HArray1OfBSplineCurve.def_static("operator delete_", (void (*)(void *, void *)) &TColGeom_HArray1OfBSplineCurve::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColGeom_HArray1OfBSplineCurve.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_HArray1OfBSplineCurve::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColGeom_HArray1OfBSplineCurve.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_HArray1OfBSplineCurve::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColGeom_HArray1OfBSplineCurve.def("Array1", (const TColGeom_Array1OfBSplineCurve & (TColGeom_HArray1OfBSplineCurve::*)() const) &TColGeom_HArray1OfBSplineCurve::Array1, "None");
cls_TColGeom_HArray1OfBSplineCurve.def("ChangeArray1", (TColGeom_Array1OfBSplineCurve & (TColGeom_HArray1OfBSplineCurve::*)()) &TColGeom_HArray1OfBSplineCurve::ChangeArray1, "None");
cls_TColGeom_HArray1OfBSplineCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom_HArray1OfBSplineCurve::get_type_name, "None");
cls_TColGeom_HArray1OfBSplineCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HArray1OfBSplineCurve::get_type_descriptor, "None");
cls_TColGeom_HArray1OfBSplineCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HArray1OfBSplineCurve::*)() const) &TColGeom_HArray1OfBSplineCurve::DynamicType, "None");

// TYPEDEF: TCOLGEOM_ARRAY1OFBEZIERCURVE
bind_NCollection_Array1<opencascade::handle<Geom_BezierCurve> >(mod, "TColGeom_Array1OfBezierCurve", py::module_local(false));

// TYPEDEF: TCOLGEOM_ARRAY2OFBEZIERSURFACE
bind_NCollection_Array2<opencascade::handle<Geom_BezierSurface> >(mod, "TColGeom_Array2OfBezierSurface", py::module_local(false));

// TYPEDEF: TCOLGEOM_SEQUENCEOFBOUNDEDCURVE
bind_NCollection_Sequence<opencascade::handle<Geom_BoundedCurve> >(mod, "TColGeom_SequenceOfBoundedCurve", py::module_local(false));

// CLASS: TCOLGEOM_HSEQUENCEOFBOUNDEDCURVE
py::class_<TColGeom_HSequenceOfBoundedCurve, opencascade::handle<TColGeom_HSequenceOfBoundedCurve>, Standard_Transient> cls_TColGeom_HSequenceOfBoundedCurve(mod, "TColGeom_HSequenceOfBoundedCurve", "None", py::multiple_inheritance());

// Constructors
cls_TColGeom_HSequenceOfBoundedCurve.def(py::init<>());
cls_TColGeom_HSequenceOfBoundedCurve.def(py::init<const TColGeom_SequenceOfBoundedCurve &>(), py::arg("theOther"));

// Methods
// cls_TColGeom_HSequenceOfBoundedCurve.def_static("operator new_", (void * (*)(size_t)) &TColGeom_HSequenceOfBoundedCurve::operator new, "None", py::arg("theSize"));
// cls_TColGeom_HSequenceOfBoundedCurve.def_static("operator delete_", (void (*)(void *)) &TColGeom_HSequenceOfBoundedCurve::operator delete, "None", py::arg("theAddress"));
// cls_TColGeom_HSequenceOfBoundedCurve.def_static("operator new[]_", (void * (*)(size_t)) &TColGeom_HSequenceOfBoundedCurve::operator new[], "None", py::arg("theSize"));
// cls_TColGeom_HSequenceOfBoundedCurve.def_static("operator delete[]_", (void (*)(void *)) &TColGeom_HSequenceOfBoundedCurve::operator delete[], "None", py::arg("theAddress"));
// cls_TColGeom_HSequenceOfBoundedCurve.def_static("operator new_", (void * (*)(size_t, void *)) &TColGeom_HSequenceOfBoundedCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColGeom_HSequenceOfBoundedCurve.def_static("operator delete_", (void (*)(void *, void *)) &TColGeom_HSequenceOfBoundedCurve::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColGeom_HSequenceOfBoundedCurve.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_HSequenceOfBoundedCurve::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColGeom_HSequenceOfBoundedCurve.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_HSequenceOfBoundedCurve::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColGeom_HSequenceOfBoundedCurve.def("Sequence", (const TColGeom_SequenceOfBoundedCurve & (TColGeom_HSequenceOfBoundedCurve::*)() const) &TColGeom_HSequenceOfBoundedCurve::Sequence, "None");
cls_TColGeom_HSequenceOfBoundedCurve.def("Append", (void (TColGeom_HSequenceOfBoundedCurve::*)(const TColGeom_SequenceOfBoundedCurve::value_type &)) &TColGeom_HSequenceOfBoundedCurve::Append, "None", py::arg("theItem"));
cls_TColGeom_HSequenceOfBoundedCurve.def("Append", (void (TColGeom_HSequenceOfBoundedCurve::*)(TColGeom_SequenceOfBoundedCurve &)) &TColGeom_HSequenceOfBoundedCurve::Append, "None", py::arg("theSequence"));
cls_TColGeom_HSequenceOfBoundedCurve.def("ChangeSequence", (TColGeom_SequenceOfBoundedCurve & (TColGeom_HSequenceOfBoundedCurve::*)()) &TColGeom_HSequenceOfBoundedCurve::ChangeSequence, "None");
cls_TColGeom_HSequenceOfBoundedCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom_HSequenceOfBoundedCurve::get_type_name, "None");
cls_TColGeom_HSequenceOfBoundedCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HSequenceOfBoundedCurve::get_type_descriptor, "None");
cls_TColGeom_HSequenceOfBoundedCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HSequenceOfBoundedCurve::*)() const) &TColGeom_HSequenceOfBoundedCurve::DynamicType, "None");

// TYPEDEF: TCOLGEOM_ARRAY2OFSURFACE
bind_NCollection_Array2<opencascade::handle<Geom_Surface> >(mod, "TColGeom_Array2OfSurface", py::module_local(false));

// CLASS: TCOLGEOM_HARRAY2OFSURFACE
py::class_<TColGeom_HArray2OfSurface, opencascade::handle<TColGeom_HArray2OfSurface>, Standard_Transient> cls_TColGeom_HArray2OfSurface(mod, "TColGeom_HArray2OfSurface", "None", py::multiple_inheritance());

// Constructors
cls_TColGeom_HArray2OfSurface.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_TColGeom_HArray2OfSurface.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColGeom_Array2OfSurface::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_TColGeom_HArray2OfSurface.def(py::init<const TColGeom_Array2OfSurface &>(), py::arg("theOther"));

// Methods
// cls_TColGeom_HArray2OfSurface.def_static("operator new_", (void * (*)(size_t)) &TColGeom_HArray2OfSurface::operator new, "None", py::arg("theSize"));
// cls_TColGeom_HArray2OfSurface.def_static("operator delete_", (void (*)(void *)) &TColGeom_HArray2OfSurface::operator delete, "None", py::arg("theAddress"));
// cls_TColGeom_HArray2OfSurface.def_static("operator new[]_", (void * (*)(size_t)) &TColGeom_HArray2OfSurface::operator new[], "None", py::arg("theSize"));
// cls_TColGeom_HArray2OfSurface.def_static("operator delete[]_", (void (*)(void *)) &TColGeom_HArray2OfSurface::operator delete[], "None", py::arg("theAddress"));
// cls_TColGeom_HArray2OfSurface.def_static("operator new_", (void * (*)(size_t, void *)) &TColGeom_HArray2OfSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColGeom_HArray2OfSurface.def_static("operator delete_", (void (*)(void *, void *)) &TColGeom_HArray2OfSurface::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColGeom_HArray2OfSurface.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_HArray2OfSurface::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColGeom_HArray2OfSurface.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_HArray2OfSurface::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColGeom_HArray2OfSurface.def("Array2", (const TColGeom_Array2OfSurface & (TColGeom_HArray2OfSurface::*)() const) &TColGeom_HArray2OfSurface::Array2, "None");
cls_TColGeom_HArray2OfSurface.def("ChangeArray2", (TColGeom_Array2OfSurface & (TColGeom_HArray2OfSurface::*)()) &TColGeom_HArray2OfSurface::ChangeArray2, "None");
cls_TColGeom_HArray2OfSurface.def_static("get_type_name_", (const char * (*)()) &TColGeom_HArray2OfSurface::get_type_name, "None");
cls_TColGeom_HArray2OfSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HArray2OfSurface::get_type_descriptor, "None");
cls_TColGeom_HArray2OfSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HArray2OfSurface::*)() const) &TColGeom_HArray2OfSurface::DynamicType, "None");

// CLASS: TCOLGEOM_HSEQUENCEOFCURVE
py::class_<TColGeom_HSequenceOfCurve, opencascade::handle<TColGeom_HSequenceOfCurve>, Standard_Transient> cls_TColGeom_HSequenceOfCurve(mod, "TColGeom_HSequenceOfCurve", "None", py::multiple_inheritance());

// Constructors
cls_TColGeom_HSequenceOfCurve.def(py::init<>());
cls_TColGeom_HSequenceOfCurve.def(py::init<const TColGeom_SequenceOfCurve &>(), py::arg("theOther"));

// Methods
// cls_TColGeom_HSequenceOfCurve.def_static("operator new_", (void * (*)(size_t)) &TColGeom_HSequenceOfCurve::operator new, "None", py::arg("theSize"));
// cls_TColGeom_HSequenceOfCurve.def_static("operator delete_", (void (*)(void *)) &TColGeom_HSequenceOfCurve::operator delete, "None", py::arg("theAddress"));
// cls_TColGeom_HSequenceOfCurve.def_static("operator new[]_", (void * (*)(size_t)) &TColGeom_HSequenceOfCurve::operator new[], "None", py::arg("theSize"));
// cls_TColGeom_HSequenceOfCurve.def_static("operator delete[]_", (void (*)(void *)) &TColGeom_HSequenceOfCurve::operator delete[], "None", py::arg("theAddress"));
// cls_TColGeom_HSequenceOfCurve.def_static("operator new_", (void * (*)(size_t, void *)) &TColGeom_HSequenceOfCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColGeom_HSequenceOfCurve.def_static("operator delete_", (void (*)(void *, void *)) &TColGeom_HSequenceOfCurve::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColGeom_HSequenceOfCurve.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_HSequenceOfCurve::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColGeom_HSequenceOfCurve.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_HSequenceOfCurve::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColGeom_HSequenceOfCurve.def("Sequence", (const TColGeom_SequenceOfCurve & (TColGeom_HSequenceOfCurve::*)() const) &TColGeom_HSequenceOfCurve::Sequence, "None");
cls_TColGeom_HSequenceOfCurve.def("Append", (void (TColGeom_HSequenceOfCurve::*)(const TColGeom_SequenceOfCurve::value_type &)) &TColGeom_HSequenceOfCurve::Append, "None", py::arg("theItem"));
cls_TColGeom_HSequenceOfCurve.def("Append", (void (TColGeom_HSequenceOfCurve::*)(TColGeom_SequenceOfCurve &)) &TColGeom_HSequenceOfCurve::Append, "None", py::arg("theSequence"));
cls_TColGeom_HSequenceOfCurve.def("ChangeSequence", (TColGeom_SequenceOfCurve & (TColGeom_HSequenceOfCurve::*)()) &TColGeom_HSequenceOfCurve::ChangeSequence, "None");
cls_TColGeom_HSequenceOfCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom_HSequenceOfCurve::get_type_name, "None");
cls_TColGeom_HSequenceOfCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HSequenceOfCurve::get_type_descriptor, "None");
cls_TColGeom_HSequenceOfCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HSequenceOfCurve::*)() const) &TColGeom_HSequenceOfCurve::DynamicType, "None");

// TYPEDEF: TCOLGEOM_ARRAY1OFCURVE
bind_NCollection_Array1<opencascade::handle<Geom_Curve> >(mod, "TColGeom_Array1OfCurve", py::module_local(false));

// CLASS: TCOLGEOM_HARRAY1OFCURVE
py::class_<TColGeom_HArray1OfCurve, opencascade::handle<TColGeom_HArray1OfCurve>, Standard_Transient> cls_TColGeom_HArray1OfCurve(mod, "TColGeom_HArray1OfCurve", "None", py::multiple_inheritance());

// Constructors
cls_TColGeom_HArray1OfCurve.def(py::init<>());
cls_TColGeom_HArray1OfCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TColGeom_HArray1OfCurve.def(py::init<const Standard_Integer, const Standard_Integer, const TColGeom_Array1OfCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TColGeom_HArray1OfCurve.def(py::init<const TColGeom_Array1OfCurve &>(), py::arg("theOther"));

// Methods
// cls_TColGeom_HArray1OfCurve.def_static("operator new_", (void * (*)(size_t)) &TColGeom_HArray1OfCurve::operator new, "None", py::arg("theSize"));
// cls_TColGeom_HArray1OfCurve.def_static("operator delete_", (void (*)(void *)) &TColGeom_HArray1OfCurve::operator delete, "None", py::arg("theAddress"));
// cls_TColGeom_HArray1OfCurve.def_static("operator new[]_", (void * (*)(size_t)) &TColGeom_HArray1OfCurve::operator new[], "None", py::arg("theSize"));
// cls_TColGeom_HArray1OfCurve.def_static("operator delete[]_", (void (*)(void *)) &TColGeom_HArray1OfCurve::operator delete[], "None", py::arg("theAddress"));
// cls_TColGeom_HArray1OfCurve.def_static("operator new_", (void * (*)(size_t, void *)) &TColGeom_HArray1OfCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColGeom_HArray1OfCurve.def_static("operator delete_", (void (*)(void *, void *)) &TColGeom_HArray1OfCurve::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColGeom_HArray1OfCurve.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_HArray1OfCurve::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColGeom_HArray1OfCurve.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_HArray1OfCurve::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColGeom_HArray1OfCurve.def("Array1", (const TColGeom_Array1OfCurve & (TColGeom_HArray1OfCurve::*)() const) &TColGeom_HArray1OfCurve::Array1, "None");
cls_TColGeom_HArray1OfCurve.def("ChangeArray1", (TColGeom_Array1OfCurve & (TColGeom_HArray1OfCurve::*)()) &TColGeom_HArray1OfCurve::ChangeArray1, "None");
cls_TColGeom_HArray1OfCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom_HArray1OfCurve::get_type_name, "None");
cls_TColGeom_HArray1OfCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HArray1OfCurve::get_type_descriptor, "None");
cls_TColGeom_HArray1OfCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HArray1OfCurve::*)() const) &TColGeom_HArray1OfCurve::DynamicType, "None");

// CLASS: TCOLGEOM_HARRAY1OFBEZIERCURVE
py::class_<TColGeom_HArray1OfBezierCurve, opencascade::handle<TColGeom_HArray1OfBezierCurve>, Standard_Transient> cls_TColGeom_HArray1OfBezierCurve(mod, "TColGeom_HArray1OfBezierCurve", "None", py::multiple_inheritance());

// Constructors
cls_TColGeom_HArray1OfBezierCurve.def(py::init<>());
cls_TColGeom_HArray1OfBezierCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TColGeom_HArray1OfBezierCurve.def(py::init<const Standard_Integer, const Standard_Integer, const TColGeom_Array1OfBezierCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TColGeom_HArray1OfBezierCurve.def(py::init<const TColGeom_Array1OfBezierCurve &>(), py::arg("theOther"));

// Methods
// cls_TColGeom_HArray1OfBezierCurve.def_static("operator new_", (void * (*)(size_t)) &TColGeom_HArray1OfBezierCurve::operator new, "None", py::arg("theSize"));
// cls_TColGeom_HArray1OfBezierCurve.def_static("operator delete_", (void (*)(void *)) &TColGeom_HArray1OfBezierCurve::operator delete, "None", py::arg("theAddress"));
// cls_TColGeom_HArray1OfBezierCurve.def_static("operator new[]_", (void * (*)(size_t)) &TColGeom_HArray1OfBezierCurve::operator new[], "None", py::arg("theSize"));
// cls_TColGeom_HArray1OfBezierCurve.def_static("operator delete[]_", (void (*)(void *)) &TColGeom_HArray1OfBezierCurve::operator delete[], "None", py::arg("theAddress"));
// cls_TColGeom_HArray1OfBezierCurve.def_static("operator new_", (void * (*)(size_t, void *)) &TColGeom_HArray1OfBezierCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColGeom_HArray1OfBezierCurve.def_static("operator delete_", (void (*)(void *, void *)) &TColGeom_HArray1OfBezierCurve::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColGeom_HArray1OfBezierCurve.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_HArray1OfBezierCurve::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColGeom_HArray1OfBezierCurve.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_HArray1OfBezierCurve::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColGeom_HArray1OfBezierCurve.def("Array1", (const TColGeom_Array1OfBezierCurve & (TColGeom_HArray1OfBezierCurve::*)() const) &TColGeom_HArray1OfBezierCurve::Array1, "None");
cls_TColGeom_HArray1OfBezierCurve.def("ChangeArray1", (TColGeom_Array1OfBezierCurve & (TColGeom_HArray1OfBezierCurve::*)()) &TColGeom_HArray1OfBezierCurve::ChangeArray1, "None");
cls_TColGeom_HArray1OfBezierCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom_HArray1OfBezierCurve::get_type_name, "None");
cls_TColGeom_HArray1OfBezierCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HArray1OfBezierCurve::get_type_descriptor, "None");
cls_TColGeom_HArray1OfBezierCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HArray1OfBezierCurve::*)() const) &TColGeom_HArray1OfBezierCurve::DynamicType, "None");

// TYPEDEF: TCOLGEOM_SEQUENCEOFSURFACE
bind_NCollection_Sequence<opencascade::handle<Geom_Surface> >(mod, "TColGeom_SequenceOfSurface", py::module_local(false));


}
