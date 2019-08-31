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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Standard_OStream.hxx>
#include <Standard_IStream.hxx>
#include <Message_ProgressIndicator.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <GeomTools_SurfaceSet.hxx>
#include <Geom_Curve.hxx>
#include <GeomTools_CurveSet.hxx>
#include <Geom2d_Curve.hxx>
#include <GeomTools_Curve2dSet.hxx>
#include <GeomTools_UndefinedTypeHandler.hxx>
#include <GeomTools.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Type.hxx>

PYBIND11_MODULE(GeomTools, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Message");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Geom2d");

// CLASS: GEOMTOOLS_SURFACESET
py::class_<GeomTools_SurfaceSet> cls_GeomTools_SurfaceSet(mod, "GeomTools_SurfaceSet", "Stores a set of Surfaces from Geom.");

// Constructors
cls_GeomTools_SurfaceSet.def(py::init<>());

// Methods
// cls_GeomTools_SurfaceSet.def_static("operator new_", (void * (*)(size_t)) &GeomTools_SurfaceSet::operator new, "None", py::arg("theSize"));
// cls_GeomTools_SurfaceSet.def_static("operator delete_", (void (*)(void *)) &GeomTools_SurfaceSet::operator delete, "None", py::arg("theAddress"));
// cls_GeomTools_SurfaceSet.def_static("operator new[]_", (void * (*)(size_t)) &GeomTools_SurfaceSet::operator new[], "None", py::arg("theSize"));
// cls_GeomTools_SurfaceSet.def_static("operator delete[]_", (void (*)(void *)) &GeomTools_SurfaceSet::operator delete[], "None", py::arg("theAddress"));
// cls_GeomTools_SurfaceSet.def_static("operator new_", (void * (*)(size_t, void *)) &GeomTools_SurfaceSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomTools_SurfaceSet.def_static("operator delete_", (void (*)(void *, void *)) &GeomTools_SurfaceSet::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomTools_SurfaceSet.def("Clear", (void (GeomTools_SurfaceSet::*)()) &GeomTools_SurfaceSet::Clear, "Clears the content of the set.");
cls_GeomTools_SurfaceSet.def("Add", (Standard_Integer (GeomTools_SurfaceSet::*)(const opencascade::handle<Geom_Surface> &)) &GeomTools_SurfaceSet::Add, "Incorporate a new Surface in the set and returns its index.", py::arg("S"));
cls_GeomTools_SurfaceSet.def("Surface", (opencascade::handle<Geom_Surface> (GeomTools_SurfaceSet::*)(const Standard_Integer) const) &GeomTools_SurfaceSet::Surface, "Returns the Surface of index <I>.", py::arg("I"));
cls_GeomTools_SurfaceSet.def("Index", (Standard_Integer (GeomTools_SurfaceSet::*)(const opencascade::handle<Geom_Surface> &) const) &GeomTools_SurfaceSet::Index, "Returns the index of <L>.", py::arg("S"));
cls_GeomTools_SurfaceSet.def("Dump", (void (GeomTools_SurfaceSet::*)(Standard_OStream &) const) &GeomTools_SurfaceSet::Dump, "Dumps the content of me on the stream <OS>.", py::arg("OS"));
cls_GeomTools_SurfaceSet.def("Write", (void (GeomTools_SurfaceSet::*)(Standard_OStream &) const) &GeomTools_SurfaceSet::Write, "Writes the content of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
cls_GeomTools_SurfaceSet.def("Read", (void (GeomTools_SurfaceSet::*)(Standard_IStream &)) &GeomTools_SurfaceSet::Read, "Reads the content of me from the stream <IS>. me is first cleared.", py::arg("IS"));
cls_GeomTools_SurfaceSet.def_static("PrintSurface_", [](const opencascade::handle<Geom_Surface> & a0, Standard_OStream & a1) -> void { return GeomTools_SurfaceSet::PrintSurface(a0, a1); });
cls_GeomTools_SurfaceSet.def_static("PrintSurface_", (void (*)(const opencascade::handle<Geom_Surface> &, Standard_OStream &, const Standard_Boolean)) &GeomTools_SurfaceSet::PrintSurface, "Dumps the surface on the stream, if compact is True use the compact format that can be read back.", py::arg("S"), py::arg("OS"), py::arg("compact"));
cls_GeomTools_SurfaceSet.def_static("ReadSurface_", (opencascade::handle<Geom_Surface> (*)(Standard_IStream &)) &GeomTools_SurfaceSet::ReadSurface, "Reads the surface from the stream. The surface is assumed to have been written with the Print method (compact = True).", py::arg("IS"));
cls_GeomTools_SurfaceSet.def("SetProgress", (void (GeomTools_SurfaceSet::*)(const opencascade::handle<Message_ProgressIndicator> &)) &GeomTools_SurfaceSet::SetProgress, "None", py::arg("PR"));
cls_GeomTools_SurfaceSet.def("GetProgress", (opencascade::handle<Message_ProgressIndicator> (GeomTools_SurfaceSet::*)() const) &GeomTools_SurfaceSet::GetProgress, "None");

// CLASS: GEOMTOOLS_CURVESET
py::class_<GeomTools_CurveSet> cls_GeomTools_CurveSet(mod, "GeomTools_CurveSet", "Stores a set of Curves from Geom.");

// Constructors
cls_GeomTools_CurveSet.def(py::init<>());

// Methods
// cls_GeomTools_CurveSet.def_static("operator new_", (void * (*)(size_t)) &GeomTools_CurveSet::operator new, "None", py::arg("theSize"));
// cls_GeomTools_CurveSet.def_static("operator delete_", (void (*)(void *)) &GeomTools_CurveSet::operator delete, "None", py::arg("theAddress"));
// cls_GeomTools_CurveSet.def_static("operator new[]_", (void * (*)(size_t)) &GeomTools_CurveSet::operator new[], "None", py::arg("theSize"));
// cls_GeomTools_CurveSet.def_static("operator delete[]_", (void (*)(void *)) &GeomTools_CurveSet::operator delete[], "None", py::arg("theAddress"));
// cls_GeomTools_CurveSet.def_static("operator new_", (void * (*)(size_t, void *)) &GeomTools_CurveSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomTools_CurveSet.def_static("operator delete_", (void (*)(void *, void *)) &GeomTools_CurveSet::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomTools_CurveSet.def("Clear", (void (GeomTools_CurveSet::*)()) &GeomTools_CurveSet::Clear, "Clears the content of the set.");
cls_GeomTools_CurveSet.def("Add", (Standard_Integer (GeomTools_CurveSet::*)(const opencascade::handle<Geom_Curve> &)) &GeomTools_CurveSet::Add, "Incorporate a new Curve in the set and returns its index.", py::arg("C"));
cls_GeomTools_CurveSet.def("Curve", (opencascade::handle<Geom_Curve> (GeomTools_CurveSet::*)(const Standard_Integer) const) &GeomTools_CurveSet::Curve, "Returns the Curve of index <I>.", py::arg("I"));
cls_GeomTools_CurveSet.def("Index", (Standard_Integer (GeomTools_CurveSet::*)(const opencascade::handle<Geom_Curve> &) const) &GeomTools_CurveSet::Index, "Returns the index of <L>.", py::arg("C"));
cls_GeomTools_CurveSet.def("Dump", (void (GeomTools_CurveSet::*)(Standard_OStream &) const) &GeomTools_CurveSet::Dump, "Dumps the content of me on the stream <OS>.", py::arg("OS"));
cls_GeomTools_CurveSet.def("Write", (void (GeomTools_CurveSet::*)(Standard_OStream &) const) &GeomTools_CurveSet::Write, "Writes the content of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
cls_GeomTools_CurveSet.def("Read", (void (GeomTools_CurveSet::*)(Standard_IStream &)) &GeomTools_CurveSet::Read, "Reads the content of me from the stream <IS>. me is first cleared.", py::arg("IS"));
cls_GeomTools_CurveSet.def_static("PrintCurve_", [](const opencascade::handle<Geom_Curve> & a0, Standard_OStream & a1) -> void { return GeomTools_CurveSet::PrintCurve(a0, a1); });
cls_GeomTools_CurveSet.def_static("PrintCurve_", (void (*)(const opencascade::handle<Geom_Curve> &, Standard_OStream &, const Standard_Boolean)) &GeomTools_CurveSet::PrintCurve, "Dumps the curve on the stream, if compact is True use the compact format that can be read back.", py::arg("C"), py::arg("OS"), py::arg("compact"));
cls_GeomTools_CurveSet.def_static("ReadCurve_", (opencascade::handle<Geom_Curve> (*)(Standard_IStream &)) &GeomTools_CurveSet::ReadCurve, "Reads the curve from the stream. The curve is assumed to have been written with the Print method (compact = True).", py::arg("IS"));
cls_GeomTools_CurveSet.def("SetProgress", (void (GeomTools_CurveSet::*)(const opencascade::handle<Message_ProgressIndicator> &)) &GeomTools_CurveSet::SetProgress, "None", py::arg("PR"));
cls_GeomTools_CurveSet.def("GetProgress", (opencascade::handle<Message_ProgressIndicator> (GeomTools_CurveSet::*)() const) &GeomTools_CurveSet::GetProgress, "None");

// CLASS: GEOMTOOLS_CURVE2DSET
py::class_<GeomTools_Curve2dSet> cls_GeomTools_Curve2dSet(mod, "GeomTools_Curve2dSet", "Stores a set of Curves from Geom2d.");

// Constructors
cls_GeomTools_Curve2dSet.def(py::init<>());

// Methods
// cls_GeomTools_Curve2dSet.def_static("operator new_", (void * (*)(size_t)) &GeomTools_Curve2dSet::operator new, "None", py::arg("theSize"));
// cls_GeomTools_Curve2dSet.def_static("operator delete_", (void (*)(void *)) &GeomTools_Curve2dSet::operator delete, "None", py::arg("theAddress"));
// cls_GeomTools_Curve2dSet.def_static("operator new[]_", (void * (*)(size_t)) &GeomTools_Curve2dSet::operator new[], "None", py::arg("theSize"));
// cls_GeomTools_Curve2dSet.def_static("operator delete[]_", (void (*)(void *)) &GeomTools_Curve2dSet::operator delete[], "None", py::arg("theAddress"));
// cls_GeomTools_Curve2dSet.def_static("operator new_", (void * (*)(size_t, void *)) &GeomTools_Curve2dSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomTools_Curve2dSet.def_static("operator delete_", (void (*)(void *, void *)) &GeomTools_Curve2dSet::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomTools_Curve2dSet.def("Clear", (void (GeomTools_Curve2dSet::*)()) &GeomTools_Curve2dSet::Clear, "Clears the content of the set.");
cls_GeomTools_Curve2dSet.def("Add", (Standard_Integer (GeomTools_Curve2dSet::*)(const opencascade::handle<Geom2d_Curve> &)) &GeomTools_Curve2dSet::Add, "Incorporate a new Curve in the set and returns its index.", py::arg("C"));
cls_GeomTools_Curve2dSet.def("Curve2d", (opencascade::handle<Geom2d_Curve> (GeomTools_Curve2dSet::*)(const Standard_Integer) const) &GeomTools_Curve2dSet::Curve2d, "Returns the Curve of index <I>.", py::arg("I"));
cls_GeomTools_Curve2dSet.def("Index", (Standard_Integer (GeomTools_Curve2dSet::*)(const opencascade::handle<Geom2d_Curve> &) const) &GeomTools_Curve2dSet::Index, "Returns the index of <L>.", py::arg("C"));
cls_GeomTools_Curve2dSet.def("Dump", (void (GeomTools_Curve2dSet::*)(Standard_OStream &) const) &GeomTools_Curve2dSet::Dump, "Dumps the content of me on the stream <OS>.", py::arg("OS"));
cls_GeomTools_Curve2dSet.def("Write", (void (GeomTools_Curve2dSet::*)(Standard_OStream &) const) &GeomTools_Curve2dSet::Write, "Writes the content of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
cls_GeomTools_Curve2dSet.def("Read", (void (GeomTools_Curve2dSet::*)(Standard_IStream &)) &GeomTools_Curve2dSet::Read, "Reads the content of me from the stream <IS>. me is first cleared.", py::arg("IS"));
cls_GeomTools_Curve2dSet.def_static("PrintCurve2d_", [](const opencascade::handle<Geom2d_Curve> & a0, Standard_OStream & a1) -> void { return GeomTools_Curve2dSet::PrintCurve2d(a0, a1); });
cls_GeomTools_Curve2dSet.def_static("PrintCurve2d_", (void (*)(const opencascade::handle<Geom2d_Curve> &, Standard_OStream &, const Standard_Boolean)) &GeomTools_Curve2dSet::PrintCurve2d, "Dumps the curve on the stream, if compact is True use the compact format that can be read back.", py::arg("C"), py::arg("OS"), py::arg("compact"));
cls_GeomTools_Curve2dSet.def_static("ReadCurve2d_", (opencascade::handle<Geom2d_Curve> (*)(Standard_IStream &)) &GeomTools_Curve2dSet::ReadCurve2d, "Reads the curve from the stream. The curve is assumed to have been written with the Print method (compact = True).", py::arg("IS"));
cls_GeomTools_Curve2dSet.def("SetProgress", (void (GeomTools_Curve2dSet::*)(const opencascade::handle<Message_ProgressIndicator> &)) &GeomTools_Curve2dSet::SetProgress, "None", py::arg("PR"));
cls_GeomTools_Curve2dSet.def("GetProgress", (opencascade::handle<Message_ProgressIndicator> (GeomTools_Curve2dSet::*)() const) &GeomTools_Curve2dSet::GetProgress, "None");

// CLASS: GEOMTOOLS
py::class_<GeomTools> cls_GeomTools(mod, "GeomTools", "The GeomTools package provides utilities for Geometry.");

// Methods
// cls_GeomTools.def_static("operator new_", (void * (*)(size_t)) &GeomTools::operator new, "None", py::arg("theSize"));
// cls_GeomTools.def_static("operator delete_", (void (*)(void *)) &GeomTools::operator delete, "None", py::arg("theAddress"));
// cls_GeomTools.def_static("operator new[]_", (void * (*)(size_t)) &GeomTools::operator new[], "None", py::arg("theSize"));
// cls_GeomTools.def_static("operator delete[]_", (void (*)(void *)) &GeomTools::operator delete[], "None", py::arg("theAddress"));
// cls_GeomTools.def_static("operator new_", (void * (*)(size_t, void *)) &GeomTools::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomTools.def_static("operator delete_", (void (*)(void *, void *)) &GeomTools::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomTools.def_static("Dump_", (void (*)(const opencascade::handle<Geom_Surface> &, Standard_OStream &)) &GeomTools::Dump, "A set of Curves from Geom2d. Dumps the surface on the stream.", py::arg("S"), py::arg("OS"));
cls_GeomTools.def_static("Write_", (void (*)(const opencascade::handle<Geom_Surface> &, Standard_OStream &)) &GeomTools::Write, "Writes the surface on the stream.", py::arg("S"), py::arg("OS"));
cls_GeomTools.def_static("Read_", (void (*)(opencascade::handle<Geom_Surface> &, Standard_IStream &)) &GeomTools::Read, "Reads the surface from the stream.", py::arg("S"), py::arg("IS"));
cls_GeomTools.def_static("Dump_", (void (*)(const opencascade::handle<Geom_Curve> &, Standard_OStream &)) &GeomTools::Dump, "Dumps the Curve on the stream.", py::arg("C"), py::arg("OS"));
cls_GeomTools.def_static("Write_", (void (*)(const opencascade::handle<Geom_Curve> &, Standard_OStream &)) &GeomTools::Write, "Writes the Curve on the stream.", py::arg("C"), py::arg("OS"));
cls_GeomTools.def_static("Read_", (void (*)(opencascade::handle<Geom_Curve> &, Standard_IStream &)) &GeomTools::Read, "Reads the Curve from the stream.", py::arg("C"), py::arg("IS"));
cls_GeomTools.def_static("Dump_", (void (*)(const opencascade::handle<Geom2d_Curve> &, Standard_OStream &)) &GeomTools::Dump, "Dumps the Curve on the stream.", py::arg("C"), py::arg("OS"));
cls_GeomTools.def_static("Write_", (void (*)(const opencascade::handle<Geom2d_Curve> &, Standard_OStream &)) &GeomTools::Write, "Writes the Curve on the stream.", py::arg("C"), py::arg("OS"));
cls_GeomTools.def_static("Read_", (void (*)(opencascade::handle<Geom2d_Curve> &, Standard_IStream &)) &GeomTools::Read, "Reads the Curve from the stream.", py::arg("C"), py::arg("IS"));
cls_GeomTools.def_static("SetUndefinedTypeHandler_", (void (*)(const opencascade::handle<GeomTools_UndefinedTypeHandler> &)) &GeomTools::SetUndefinedTypeHandler, "None", py::arg("aHandler"));
cls_GeomTools.def_static("GetUndefinedTypeHandler_", (opencascade::handle<GeomTools_UndefinedTypeHandler> (*)()) &GeomTools::GetUndefinedTypeHandler, "None");
cls_GeomTools.def_static("GetReal_", [](Standard_IStream & IS, Standard_Real & theValue){ GeomTools::GetReal(IS, theValue); return theValue; }, "Reads the Standard_Real value from the stream. Zero is read in case of error", py::arg("IS"), py::arg("theValue"));

// CLASS: GEOMTOOLS_UNDEFINEDTYPEHANDLER
py::class_<GeomTools_UndefinedTypeHandler, opencascade::handle<GeomTools_UndefinedTypeHandler>, Standard_Transient> cls_GeomTools_UndefinedTypeHandler(mod, "GeomTools_UndefinedTypeHandler", "None");

// Constructors
cls_GeomTools_UndefinedTypeHandler.def(py::init<>());

// Methods
cls_GeomTools_UndefinedTypeHandler.def("PrintCurve", [](GeomTools_UndefinedTypeHandler &self, const opencascade::handle<Geom_Curve> & a0, Standard_OStream & a1) -> void { return self.PrintCurve(a0, a1); });
cls_GeomTools_UndefinedTypeHandler.def("PrintCurve", (void (GeomTools_UndefinedTypeHandler::*)(const opencascade::handle<Geom_Curve> &, Standard_OStream &, const Standard_Boolean) const) &GeomTools_UndefinedTypeHandler::PrintCurve, "None", py::arg("C"), py::arg("OS"), py::arg("compact"));
cls_GeomTools_UndefinedTypeHandler.def("ReadCurve", (Standard_IStream & (GeomTools_UndefinedTypeHandler::*)(const Standard_Integer, Standard_IStream &, opencascade::handle<Geom_Curve> &) const) &GeomTools_UndefinedTypeHandler::ReadCurve, "None", py::arg("ctype"), py::arg("IS"), py::arg("C"));
cls_GeomTools_UndefinedTypeHandler.def("PrintCurve2d", [](GeomTools_UndefinedTypeHandler &self, const opencascade::handle<Geom2d_Curve> & a0, Standard_OStream & a1) -> void { return self.PrintCurve2d(a0, a1); });
cls_GeomTools_UndefinedTypeHandler.def("PrintCurve2d", (void (GeomTools_UndefinedTypeHandler::*)(const opencascade::handle<Geom2d_Curve> &, Standard_OStream &, const Standard_Boolean) const) &GeomTools_UndefinedTypeHandler::PrintCurve2d, "None", py::arg("C"), py::arg("OS"), py::arg("compact"));
cls_GeomTools_UndefinedTypeHandler.def("ReadCurve2d", (Standard_IStream & (GeomTools_UndefinedTypeHandler::*)(const Standard_Integer, Standard_IStream &, opencascade::handle<Geom2d_Curve> &) const) &GeomTools_UndefinedTypeHandler::ReadCurve2d, "None", py::arg("ctype"), py::arg("IS"), py::arg("C"));
cls_GeomTools_UndefinedTypeHandler.def("PrintSurface", [](GeomTools_UndefinedTypeHandler &self, const opencascade::handle<Geom_Surface> & a0, Standard_OStream & a1) -> void { return self.PrintSurface(a0, a1); });
cls_GeomTools_UndefinedTypeHandler.def("PrintSurface", (void (GeomTools_UndefinedTypeHandler::*)(const opencascade::handle<Geom_Surface> &, Standard_OStream &, const Standard_Boolean) const) &GeomTools_UndefinedTypeHandler::PrintSurface, "None", py::arg("S"), py::arg("OS"), py::arg("compact"));
cls_GeomTools_UndefinedTypeHandler.def("ReadSurface", (Standard_IStream & (GeomTools_UndefinedTypeHandler::*)(const Standard_Integer, Standard_IStream &, opencascade::handle<Geom_Surface> &) const) &GeomTools_UndefinedTypeHandler::ReadSurface, "None", py::arg("ctype"), py::arg("IS"), py::arg("S"));
cls_GeomTools_UndefinedTypeHandler.def_static("get_type_name_", (const char * (*)()) &GeomTools_UndefinedTypeHandler::get_type_name, "None");
cls_GeomTools_UndefinedTypeHandler.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomTools_UndefinedTypeHandler::get_type_descriptor, "None");
cls_GeomTools_UndefinedTypeHandler.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomTools_UndefinedTypeHandler::*)() const) &GeomTools_UndefinedTypeHandler::DynamicType, "None");


}
