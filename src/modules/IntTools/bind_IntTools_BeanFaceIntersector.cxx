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
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IntTools_Context.hxx>
#include <IntTools_SequenceOfRanges.hxx>
#include <IntTools_CurveRangeSample.hxx>
#include <Bnd_Box.hxx>
#include <IntTools_SurfaceRangeSample.hxx>
#include <IntTools_CurveRangeLocalizeData.hxx>
#include <IntTools_SurfaceRangeLocalizeData.hxx>
#include <IntTools_ListOfCurveRangeSample.hxx>
#include <IntTools_ListOfSurfaceRangeSample.hxx>
#include <Geom_Surface.hxx>
#include <Extrema_ExtCS.hxx>
#include <GeomAPI_ProjectPointOnSurf.hxx>
#include <IntTools_MarkedRangeSet.hxx>
#include <IntTools_BeanFaceIntersector.hxx>

void bind_IntTools_BeanFaceIntersector(py::module &mod){

py::class_<IntTools_BeanFaceIntersector, std::unique_ptr<IntTools_BeanFaceIntersector>> cls_IntTools_BeanFaceIntersector(mod, "IntTools_BeanFaceIntersector", "The class BeanFaceIntersector computes ranges of parameters on the curve of a bean(part of edge) that bound the parts of bean which are on the surface of a face according to edge and face tolerances. Warning: The real boundaries of the face are not taken into account, Most of the result parts of the bean lays only inside the region of the surface, which includes the inside of the face. And the parts which are out of this region can be excluded from the result.");

// Constructors
cls_IntTools_BeanFaceIntersector.def(py::init<>());
cls_IntTools_BeanFaceIntersector.def(py::init<const TopoDS_Edge &, const TopoDS_Face &>(), py::arg("theEdge"), py::arg("theFace"));
cls_IntTools_BeanFaceIntersector.def(py::init<const BRepAdaptor_Curve &, const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real>(), py::arg("theCurve"), py::arg("theSurface"), py::arg("theBeanTolerance"), py::arg("theFaceTolerance"));
cls_IntTools_BeanFaceIntersector.def(py::init<const BRepAdaptor_Curve &, const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theCurve"), py::arg("theSurface"), py::arg("theFirstParOnCurve"), py::arg("theLastParOnCurve"), py::arg("theUMinParameter"), py::arg("theUMaxParameter"), py::arg("theVMinParameter"), py::arg("theVMaxParameter"), py::arg("theBeanTolerance"), py::arg("theFaceTolerance"));

// Fields

// Methods
// cls_IntTools_BeanFaceIntersector.def_static("operator new_", (void * (*)(size_t)) &IntTools_BeanFaceIntersector::operator new, "None", py::arg("theSize"));
// cls_IntTools_BeanFaceIntersector.def_static("operator delete_", (void (*)(void *)) &IntTools_BeanFaceIntersector::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_BeanFaceIntersector.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_BeanFaceIntersector::operator new[], "None", py::arg("theSize"));
// cls_IntTools_BeanFaceIntersector.def_static("operator delete[]_", (void (*)(void *)) &IntTools_BeanFaceIntersector::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_BeanFaceIntersector.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_BeanFaceIntersector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_BeanFaceIntersector.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_BeanFaceIntersector::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_BeanFaceIntersector.def("Init", (void (IntTools_BeanFaceIntersector::*)(const TopoDS_Edge &, const TopoDS_Face &)) &IntTools_BeanFaceIntersector::Init, "Initializes the algorithm", py::arg("theEdge"), py::arg("theFace"));
cls_IntTools_BeanFaceIntersector.def("Init", (void (IntTools_BeanFaceIntersector::*)(const BRepAdaptor_Curve &, const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real)) &IntTools_BeanFaceIntersector::Init, "Initializes the algorithm", py::arg("theCurve"), py::arg("theSurface"), py::arg("theBeanTolerance"), py::arg("theFaceTolerance"));
cls_IntTools_BeanFaceIntersector.def("Init", (void (IntTools_BeanFaceIntersector::*)(const BRepAdaptor_Curve &, const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntTools_BeanFaceIntersector::Init, "Initializes the algorithm theUMinParameter, ... are used for optimization purposes", py::arg("theCurve"), py::arg("theSurface"), py::arg("theFirstParOnCurve"), py::arg("theLastParOnCurve"), py::arg("theUMinParameter"), py::arg("theUMaxParameter"), py::arg("theVMinParameter"), py::arg("theVMaxParameter"), py::arg("theBeanTolerance"), py::arg("theFaceTolerance"));
cls_IntTools_BeanFaceIntersector.def("SetContext", (void (IntTools_BeanFaceIntersector::*)(const opencascade::handle<IntTools_Context> &)) &IntTools_BeanFaceIntersector::SetContext, "Sets the intersecton context", py::arg("theContext"));
cls_IntTools_BeanFaceIntersector.def("Context", (const opencascade::handle<IntTools_Context> & (IntTools_BeanFaceIntersector::*)() const) &IntTools_BeanFaceIntersector::Context, "Gets the intersecton context");
cls_IntTools_BeanFaceIntersector.def("SetBeanParameters", (void (IntTools_BeanFaceIntersector::*)(const Standard_Real, const Standard_Real)) &IntTools_BeanFaceIntersector::SetBeanParameters, "Set restrictions for curve", py::arg("theFirstParOnCurve"), py::arg("theLastParOnCurve"));
cls_IntTools_BeanFaceIntersector.def("SetSurfaceParameters", (void (IntTools_BeanFaceIntersector::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntTools_BeanFaceIntersector::SetSurfaceParameters, "Set restrictions for surface", py::arg("theUMinParameter"), py::arg("theUMaxParameter"), py::arg("theVMinParameter"), py::arg("theVMaxParameter"));
cls_IntTools_BeanFaceIntersector.def("Perform", (void (IntTools_BeanFaceIntersector::*)()) &IntTools_BeanFaceIntersector::Perform, "Launches the algorithm");
cls_IntTools_BeanFaceIntersector.def("IsDone", (Standard_Boolean (IntTools_BeanFaceIntersector::*)() const) &IntTools_BeanFaceIntersector::IsDone, "Returns Done/NotDone state of the algorithm.");
cls_IntTools_BeanFaceIntersector.def("Result", (const IntTools_SequenceOfRanges & (IntTools_BeanFaceIntersector::*)() const) &IntTools_BeanFaceIntersector::Result, "None");
cls_IntTools_BeanFaceIntersector.def("Result", (void (IntTools_BeanFaceIntersector::*)(IntTools_SequenceOfRanges &) const) &IntTools_BeanFaceIntersector::Result, "None", py::arg("theResults"));

// Enums

}