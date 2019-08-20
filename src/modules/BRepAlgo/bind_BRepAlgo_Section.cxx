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
#include <BRepAlgo_BooleanOperation.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pln.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <BRepAlgo_Section.hxx>

void bind_BRepAlgo_Section(py::module &mod){

py::class_<BRepAlgo_Section, std::unique_ptr<BRepAlgo_Section>, BRepAlgo_BooleanOperation> cls_BRepAlgo_Section(mod, "BRepAlgo_Section", "Construction of the section lines between two shapes. For this Boolean operation, each face of the first shape is intersected by each face of the second shape. The resulting intersection edges are brought together into a compound object, but not chained or grouped into wires. Computation of the intersection of two Shapes or Surfaces The two parts involved in this Boolean operation may be defined from geometric surfaces: the most common use is the computation of the planar section of a shape. A Section object provides the framework for: - defining the shapes to be intersected, and the computation options, - implementing the construction algorithm, and - consulting the result. Example : giving two shapes S1,S2 accessing faces, let compute the section edges R on S1,S2, performing approximation on new curves, performing PCurve on part 1 but not on part 2 : Standard_Boolean PerformNow = Standard_False; BRepBoolAPI_Section S(S1,S2,PerformNow); S.ComputePCurveOn1(Standard_True); S.Approximation(Standard_True); S.Build(); TopoDS_Shape R = S.Shape(); On Null Shapes of geometries, NotDone() is called.");

// Constructors
cls_BRepAlgo_Section.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("Sh1"), py::arg("Sh2"));
cls_BRepAlgo_Section.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean>(), py::arg("Sh1"), py::arg("Sh2"), py::arg("PerformNow"));
cls_BRepAlgo_Section.def(py::init<const TopoDS_Shape &, const gp_Pln &>(), py::arg("Sh"), py::arg("Pl"));
cls_BRepAlgo_Section.def(py::init<const TopoDS_Shape &, const gp_Pln &, const Standard_Boolean>(), py::arg("Sh"), py::arg("Pl"), py::arg("PerformNow"));
cls_BRepAlgo_Section.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Surface> &>(), py::arg("Sh"), py::arg("Sf"));
cls_BRepAlgo_Section.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Surface> &, const Standard_Boolean>(), py::arg("Sh"), py::arg("Sf"), py::arg("PerformNow"));
cls_BRepAlgo_Section.def(py::init<const opencascade::handle<Geom_Surface> &, const TopoDS_Shape &>(), py::arg("Sf"), py::arg("Sh"));
cls_BRepAlgo_Section.def(py::init<const opencascade::handle<Geom_Surface> &, const TopoDS_Shape &, const Standard_Boolean>(), py::arg("Sf"), py::arg("Sh"), py::arg("PerformNow"));
cls_BRepAlgo_Section.def(py::init<const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &>(), py::arg("Sf1"), py::arg("Sf2"));
cls_BRepAlgo_Section.def(py::init<const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const Standard_Boolean>(), py::arg("Sf1"), py::arg("Sf2"), py::arg("PerformNow"));

// Fields

// Methods
// cls_BRepAlgo_Section.def_static("operator new_", (void * (*)(size_t)) &BRepAlgo_Section::operator new, "None", py::arg("theSize"));
// cls_BRepAlgo_Section.def_static("operator delete_", (void (*)(void *)) &BRepAlgo_Section::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgo_Section.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgo_Section::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgo_Section.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgo_Section::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgo_Section.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgo_Section::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgo_Section.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgo_Section::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgo_Section.def("Init1", (void (BRepAlgo_Section::*)(const TopoDS_Shape &)) &BRepAlgo_Section::Init1, "Initializes the first part", py::arg("S1"));
cls_BRepAlgo_Section.def("Init1", (void (BRepAlgo_Section::*)(const gp_Pln &)) &BRepAlgo_Section::Init1, "Initializes the first part", py::arg("Pl"));
cls_BRepAlgo_Section.def("Init1", (void (BRepAlgo_Section::*)(const opencascade::handle<Geom_Surface> &)) &BRepAlgo_Section::Init1, "Initializes the first part", py::arg("Sf"));
cls_BRepAlgo_Section.def("Init2", (void (BRepAlgo_Section::*)(const TopoDS_Shape &)) &BRepAlgo_Section::Init2, "initialize second part", py::arg("S2"));
cls_BRepAlgo_Section.def("Init2", (void (BRepAlgo_Section::*)(const gp_Pln &)) &BRepAlgo_Section::Init2, "Initializes the second part", py::arg("Pl"));
cls_BRepAlgo_Section.def("Init2", (void (BRepAlgo_Section::*)(const opencascade::handle<Geom_Surface> &)) &BRepAlgo_Section::Init2, "This and the above algorithms reinitialize the first and the second parts on which this algorithm is going to perform the intersection computation. This is done with either: the surface Sf, the plane Pl or the shape Sh. You use the function Build to construct the result.", py::arg("Sf"));
cls_BRepAlgo_Section.def("Approximation", (void (BRepAlgo_Section::*)(const Standard_Boolean)) &BRepAlgo_Section::Approximation, "Defines an option for computation of further intersections. This computation will be performed by the function Build in this framework. By default, the underlying 3D geometry attached to each elementary edge of the result of a computed intersection is: - analytic where possible, provided the corresponding geometry corresponds to a type of analytic curve defined in the Geom package; for example the intersection of a cylindrical shape with a plane gives an ellipse or a circle; - or elsewhere, given as a succession of points grouped together in a BSpline curve of degree 1. If Approx equals true, when further computations are performed in this framework with the function Build, these edges will have an attached 3D geometry which is a BSpline approximation of the computed set of points. Note that as a result, approximations will be computed on edges built only on new intersection lines.", py::arg("B"));
cls_BRepAlgo_Section.def("ComputePCurveOn1", (void (BRepAlgo_Section::*)(const Standard_Boolean)) &BRepAlgo_Section::ComputePCurveOn1, "Indicates if the Pcurve must be (or not) performed on first part.", py::arg("B"));
cls_BRepAlgo_Section.def("ComputePCurveOn2", (void (BRepAlgo_Section::*)(const Standard_Boolean)) &BRepAlgo_Section::ComputePCurveOn2, "Define options for the computation of further intersections which will be performed by the function Build in this framework. By default, no parametric 2D curve (pcurve) is defined for the elementary edges of the result. If ComputePCurve1 equals true, further computations performed in this framework with the function Build will attach an additional pcurve in the parametric space of the first shape to the constructed edges. If ComputePCurve2 equals true, the additional pcurve will be attached to the constructed edges in the parametric space of the second shape. These two functions may be used together. Note that as a result, pcurves will only be added onto edges built on new intersection lines.", py::arg("B"));
cls_BRepAlgo_Section.def("Build", (void (BRepAlgo_Section::*)()) &BRepAlgo_Section::Build, "Performs the computation of the section lines between the two parts defined at the time of construction of this framework or reinitialized with the Init1 and Init2 functions. The constructed shape will be returned by the function Shape. This is a compound object composed of edges. These intersection edges may be built: - on new intersection lines, or - on coincident portions of edges in the two intersected shapes. These intersection edges are independent: they are not chained or grouped into wires. If no intersection edge exists, the result is an empty compound object. The shapes involved in the construction of the section lines can be retrieved with the function Shape1 or Shape2. Note that other objects than TopoDS_Shape shapes given as arguments at the construction time of this framework, or to the Init1 or Init2 function, are converted into faces or shells before performing the computation of the intersection. Parametric 2D curves on intersection edges No parametric 2D curve (pcurve) is defined for the elementary edges of the result. To attach parametric curves like this to the constructed edges you have to use: - the function ComputePCurveOn1 to ask for the additional computation of a pcurve in the parametric space of the first shape, - the function ComputePCurveOn2 to ask for the additional computation of a pcurve in the parametric space of the second shape. This must be done before calling this function. Note that as a result, pcurves are added on edges built on new intersection lines only. Approximation of intersection edges The underlying 3D geometry attached to each elementary edge of the result is: - analytic where possible provided the corresponding geometry corresponds to a type of analytic curve defined in the Geom package; for example, the intersection of a cylindrical shape with a plane gives an ellipse or a circle; or - elsewhere, given as a succession of points grouped together in a BSpline curve of degree 1. If, on computed elementary intersection edges whose underlying geometry is not analytic, you prefer to have an attached 3D geometry which is a BSpline approximation of the computed set of points, you have to use the function Approximation to ask for this computation option before calling this function. You may also have combined these computation options: look at the example given above to illustrate the use of the constructors.");
cls_BRepAlgo_Section.def("HasAncestorFaceOn1", (Standard_Boolean (BRepAlgo_Section::*)(const TopoDS_Shape &, TopoDS_Shape &) const) &BRepAlgo_Section::HasAncestorFaceOn1, "Identifies the ancestor faces of the new intersection edge E resulting from the last computation performed in this framework, that is, the faces of the two original shapes on which the edge E lies: - HasAncestorFaceOn1 gives the ancestor face in the first shape, and These functions return: - true if an ancestor face F is found, or - false if not. An ancestor face is identifiable for the edge E if the three following conditions are satisfied: - the first part on which this algorithm performed its last computation is a shape, that is, it was not given as a surface or a plane at the time of construction of this algorithm or at a later time by the Init1 function, - E is one of the elementary edges built by the last computation of this section algorithm, - the edge E is built on an intersection curve. In other words, E is a new edge built on the intersection curve, not on edges belonging to the intersecting shapes. To use these functions properly, you have to test the returned Boolean value before using the ancestor face: F is significant only if the returned Boolean value equals true.", py::arg("E"), py::arg("F"));
cls_BRepAlgo_Section.def("HasAncestorFaceOn2", (Standard_Boolean (BRepAlgo_Section::*)(const TopoDS_Shape &, TopoDS_Shape &) const) &BRepAlgo_Section::HasAncestorFaceOn2, "Identifies the ancestor faces of the new intersection edge E resulting from the last computation performed in this framework, that is, the faces of the two original shapes on which the edge E lies: - HasAncestorFaceOn2 gives the ancestor face in the second shape. These functions return: - true if an ancestor face F is found, or - false if not. An ancestor face is identifiable for the edge E if the three following conditions are satisfied: - the first part on which this algorithm performed its last computation is a shape, that is, it was not given as a surface or a plane at the time of construction of this algorithm or at a later time by the Init1 function, - E is one of the elementary edges built by the last computation of this section algorithm, - the edge E is built on an intersection curve. In other words, E is a new edge built on the intersection curve, not on edges belonging to the intersecting shapes. To use these functions properly, you have to test the returned Boolean value before using the ancestor face: F is significant only if the returned Boolean value equals true.", py::arg("E"), py::arg("F"));

// Enums

}