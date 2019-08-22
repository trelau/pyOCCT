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
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Lin.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <gp_Pnt.hxx>
#include <IntCurveSurface_TransitionOnCurve.hxx>
#include <TopAbs_State.hxx>
#include <gp_Pnt2d.hxx>
#include <Bnd_Box.hxx>
#include <IntCurveSurface_HInter.hxx>
#include <BRepTopAdaptor_TopolTool.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <IntCurveSurface_SequenceOfPnt.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <IntCurvesFace_Intersector.hxx>

void bind_IntCurvesFace_Intersector(py::module &mod){

py::class_<IntCurvesFace_Intersector> cls_IntCurvesFace_Intersector(mod, "IntCurvesFace_Intersector", "None");

// Constructors
cls_IntCurvesFace_Intersector.def(py::init<const TopoDS_Face &, const Standard_Real>(), py::arg("F"), py::arg("aTol"));
cls_IntCurvesFace_Intersector.def(py::init<const TopoDS_Face &, const Standard_Real, const Standard_Boolean>(), py::arg("F"), py::arg("aTol"), py::arg("aRestr"));
cls_IntCurvesFace_Intersector.def(py::init<const TopoDS_Face &, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("F"), py::arg("aTol"), py::arg("aRestr"), py::arg("UseBToler"));

// Fields

// Methods
// cls_IntCurvesFace_Intersector.def_static("operator new_", (void * (*)(size_t)) &IntCurvesFace_Intersector::operator new, "None", py::arg("theSize"));
// cls_IntCurvesFace_Intersector.def_static("operator delete_", (void (*)(void *)) &IntCurvesFace_Intersector::operator delete, "None", py::arg("theAddress"));
// cls_IntCurvesFace_Intersector.def_static("operator new[]_", (void * (*)(size_t)) &IntCurvesFace_Intersector::operator new[], "None", py::arg("theSize"));
// cls_IntCurvesFace_Intersector.def_static("operator delete[]_", (void (*)(void *)) &IntCurvesFace_Intersector::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurvesFace_Intersector.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurvesFace_Intersector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurvesFace_Intersector.def_static("operator delete_", (void (*)(void *, void *)) &IntCurvesFace_Intersector::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurvesFace_Intersector.def("Perform", (void (IntCurvesFace_Intersector::*)(const gp_Lin &, const Standard_Real, const Standard_Real)) &IntCurvesFace_Intersector::Perform, "Perform the intersection between the segment L and the loaded face.", py::arg("L"), py::arg("PInf"), py::arg("PSup"));
cls_IntCurvesFace_Intersector.def("Perform", (void (IntCurvesFace_Intersector::*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Real)) &IntCurvesFace_Intersector::Perform, "same method for a HCurve from Adaptor3d. PInf an PSup can also be - and + INF.", py::arg("HCu"), py::arg("PInf"), py::arg("PSup"));
cls_IntCurvesFace_Intersector.def("SurfaceType", (GeomAbs_SurfaceType (IntCurvesFace_Intersector::*)() const) &IntCurvesFace_Intersector::SurfaceType, "Return the surface type");
cls_IntCurvesFace_Intersector.def("IsDone", (Standard_Boolean (IntCurvesFace_Intersector::*)() const) &IntCurvesFace_Intersector::IsDone, "True is returned when the intersection have been computed.");
cls_IntCurvesFace_Intersector.def("NbPnt", (Standard_Integer (IntCurvesFace_Intersector::*)() const) &IntCurvesFace_Intersector::NbPnt, "None");
cls_IntCurvesFace_Intersector.def("UParameter", (Standard_Real (IntCurvesFace_Intersector::*)(const Standard_Integer) const) &IntCurvesFace_Intersector::UParameter, "Returns the U parameter of the ith intersection point on the surface.", py::arg("I"));
cls_IntCurvesFace_Intersector.def("VParameter", (Standard_Real (IntCurvesFace_Intersector::*)(const Standard_Integer) const) &IntCurvesFace_Intersector::VParameter, "Returns the V parameter of the ith intersection point on the surface.", py::arg("I"));
cls_IntCurvesFace_Intersector.def("WParameter", (Standard_Real (IntCurvesFace_Intersector::*)(const Standard_Integer) const) &IntCurvesFace_Intersector::WParameter, "Returns the parameter of the ith intersection point on the line.", py::arg("I"));
cls_IntCurvesFace_Intersector.def("Pnt", (const gp_Pnt & (IntCurvesFace_Intersector::*)(const Standard_Integer) const) &IntCurvesFace_Intersector::Pnt, "Returns the geometric point of the ith intersection between the line and the surface.", py::arg("I"));
cls_IntCurvesFace_Intersector.def("Transition", (IntCurveSurface_TransitionOnCurve (IntCurvesFace_Intersector::*)(const Standard_Integer) const) &IntCurvesFace_Intersector::Transition, "Returns the ith transition of the line on the surface.", py::arg("I"));
cls_IntCurvesFace_Intersector.def("State", (TopAbs_State (IntCurvesFace_Intersector::*)(const Standard_Integer) const) &IntCurvesFace_Intersector::State, "Returns the ith state of the point on the face. The values can be either TopAbs_IN ( the point is in the face) or TopAbs_ON ( the point is on a boudary of the face).", py::arg("I"));
cls_IntCurvesFace_Intersector.def("IsParallel", (Standard_Boolean (IntCurvesFace_Intersector::*)() const) &IntCurvesFace_Intersector::IsParallel, "Returns true if curve is parallel or belongs face surface This case is recognized only for some pairs of analytical curves and surfaces (plane - line, ...)");
cls_IntCurvesFace_Intersector.def("Face", (const TopoDS_Face & (IntCurvesFace_Intersector::*)() const) &IntCurvesFace_Intersector::Face, "Returns the significant face used to determine the intersection.");
cls_IntCurvesFace_Intersector.def("ClassifyUVPoint", (TopAbs_State (IntCurvesFace_Intersector::*)(const gp_Pnt2d &) const) &IntCurvesFace_Intersector::ClassifyUVPoint, "None", py::arg("Puv"));
cls_IntCurvesFace_Intersector.def("Bounding", (Bnd_Box (IntCurvesFace_Intersector::*)() const) &IntCurvesFace_Intersector::Bounding, "None");
cls_IntCurvesFace_Intersector.def("SetUseBoundToler", (void (IntCurvesFace_Intersector::*)(Standard_Boolean)) &IntCurvesFace_Intersector::SetUseBoundToler, "Sets the boundary tolerance flag", py::arg("UseBToler"));
cls_IntCurvesFace_Intersector.def("GetUseBoundToler", (Standard_Boolean (IntCurvesFace_Intersector::*)() const) &IntCurvesFace_Intersector::GetUseBoundToler, "Returns the boundary tolerance flag");
cls_IntCurvesFace_Intersector.def("Destroy", (void (IntCurvesFace_Intersector::*)()) &IntCurvesFace_Intersector::Destroy, "None");

// Enums

}