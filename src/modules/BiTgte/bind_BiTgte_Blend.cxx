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
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BiTgte_ContactType.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <TopTools_DataMapOfShapeBox.hxx>
#include <BRepOffset_Offset.hxx>
#include <BRepOffset_Inter3d.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BRepOffset_Analyse.hxx>
#include <BRepOffset_DataMapOfShapeOffset.hxx>
#include <BRepAlgo_Image.hxx>
#include <BRepAlgo_AsDes.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <BiTgte_Blend.hxx>

void bind_BiTgte_Blend(py::module &mod){

py::class_<BiTgte_Blend> cls_BiTgte_Blend(mod, "BiTgte_Blend", "Root class");

// Constructors
cls_BiTgte_Blend.def(py::init<>());
cls_BiTgte_Blend.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("S"), py::arg("Radius"), py::arg("Tol"), py::arg("NUBS"));

// Fields

// Methods
// cls_BiTgte_Blend.def_static("operator new_", (void * (*)(size_t)) &BiTgte_Blend::operator new, "None", py::arg("theSize"));
// cls_BiTgte_Blend.def_static("operator delete_", (void (*)(void *)) &BiTgte_Blend::operator delete, "None", py::arg("theAddress"));
// cls_BiTgte_Blend.def_static("operator new[]_", (void * (*)(size_t)) &BiTgte_Blend::operator new[], "None", py::arg("theSize"));
// cls_BiTgte_Blend.def_static("operator delete[]_", (void (*)(void *)) &BiTgte_Blend::operator delete[], "None", py::arg("theAddress"));
// cls_BiTgte_Blend.def_static("operator new_", (void * (*)(size_t, void *)) &BiTgte_Blend::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BiTgte_Blend.def_static("operator delete_", (void (*)(void *, void *)) &BiTgte_Blend::operator delete, "None", py::arg(""), py::arg(""));
cls_BiTgte_Blend.def("Init", (void (BiTgte_Blend::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &BiTgte_Blend::Init, "None", py::arg("S"), py::arg("Radius"), py::arg("Tol"), py::arg("NUBS"));
cls_BiTgte_Blend.def("Clear", (void (BiTgte_Blend::*)()) &BiTgte_Blend::Clear, "Clear all the Fields.");
cls_BiTgte_Blend.def("SetFaces", (void (BiTgte_Blend::*)(const TopoDS_Face &, const TopoDS_Face &)) &BiTgte_Blend::SetFaces, "Set two faces of <myShape> on which the Sphere must roll.", py::arg("F1"), py::arg("F2"));
cls_BiTgte_Blend.def("SetEdge", (void (BiTgte_Blend::*)(const TopoDS_Edge &)) &BiTgte_Blend::SetEdge, "Set an edge of <myShape> to be rounded.", py::arg("Edge"));
cls_BiTgte_Blend.def("SetStoppingFace", (void (BiTgte_Blend::*)(const TopoDS_Face &)) &BiTgte_Blend::SetStoppingFace, "Set a face on which the fillet must stop.", py::arg("Face"));
cls_BiTgte_Blend.def("Perform", [](BiTgte_Blend &self) -> void { return self.Perform(); });
cls_BiTgte_Blend.def("Perform", (void (BiTgte_Blend::*)(const Standard_Boolean)) &BiTgte_Blend::Perform, "Compute the generated surfaces. If <BuildShape> is true, compute the resulting Shape. If false, only the blending surfaces are computed.", py::arg("BuildShape"));
cls_BiTgte_Blend.def("IsDone", (Standard_Boolean (BiTgte_Blend::*)() const) &BiTgte_Blend::IsDone, "None");
cls_BiTgte_Blend.def("Shape", (const TopoDS_Shape & (BiTgte_Blend::*)() const) &BiTgte_Blend::Shape, "returns the result");
cls_BiTgte_Blend.def("NbSurfaces", (Standard_Integer (BiTgte_Blend::*)() const) &BiTgte_Blend::NbSurfaces, "returns the Number of generated surfaces.");
cls_BiTgte_Blend.def("Surface", (opencascade::handle<Geom_Surface> (BiTgte_Blend::*)(const Standard_Integer) const) &BiTgte_Blend::Surface, "returns the surface of range Index", py::arg("Index"));
cls_BiTgte_Blend.def("Face", (const TopoDS_Face & (BiTgte_Blend::*)(const Standard_Integer) const) &BiTgte_Blend::Face, "returns the surface of range Index", py::arg("Index"));
cls_BiTgte_Blend.def("CenterLines", (void (BiTgte_Blend::*)(TopTools_ListOfShape &) const) &BiTgte_Blend::CenterLines, "set in <LC> all the center lines", py::arg("LC"));
cls_BiTgte_Blend.def("Surface", (opencascade::handle<Geom_Surface> (BiTgte_Blend::*)(const TopoDS_Shape &) const) &BiTgte_Blend::Surface, "returns the surface generated by the centerline. <CenterLine> may be - an edge : generate a pipe. - a vertex : generate a sphere. Warning: returns a Null Handle if <CenterLine> generates no surface.", py::arg("CenterLine"));
cls_BiTgte_Blend.def("Face", (const TopoDS_Face & (BiTgte_Blend::*)(const TopoDS_Shape &) const) &BiTgte_Blend::Face, "returns the face generated by the centerline. <CenterLine> may be - an edge : generate a pipe. - a vertex : generate a sphere. Warning: returns a Null Shape if <CenterLine> generates no surface.", py::arg("CenterLine"));
cls_BiTgte_Blend.def("ContactType", (BiTgte_ContactType (BiTgte_Blend::*)(const Standard_Integer) const) &BiTgte_Blend::ContactType, "returns the type of contact", py::arg("Index"));
cls_BiTgte_Blend.def("SupportShape1", (const TopoDS_Shape & (BiTgte_Blend::*)(const Standard_Integer) const) &BiTgte_Blend::SupportShape1, "gives the first support shape relative to SurfaceFillet(Index);", py::arg("Index"));
cls_BiTgte_Blend.def("SupportShape2", (const TopoDS_Shape & (BiTgte_Blend::*)(const Standard_Integer) const) &BiTgte_Blend::SupportShape2, "gives the second support shape relative to SurfaceFillet(Index);", py::arg("Index"));
cls_BiTgte_Blend.def("CurveOnShape1", (opencascade::handle<Geom_Curve> (BiTgte_Blend::*)(const Standard_Integer) const) &BiTgte_Blend::CurveOnShape1, "gives the 3d curve of SurfaceFillet(Index) on SupportShape1(Index)", py::arg("Index"));
cls_BiTgte_Blend.def("CurveOnShape2", (opencascade::handle<Geom_Curve> (BiTgte_Blend::*)(const Standard_Integer) const) &BiTgte_Blend::CurveOnShape2, "gives the 3d curve of SurfaceFillet(Index) on SupportShape2(Index)", py::arg("Index"));
cls_BiTgte_Blend.def("PCurveOnFace1", (opencascade::handle<Geom2d_Curve> (BiTgte_Blend::*)(const Standard_Integer) const) &BiTgte_Blend::PCurveOnFace1, "gives the PCurve associated to CurvOnShape1(Index) on the support face Warning: returns a Null Handle if SupportShape1 is not a Face", py::arg("Index"));
cls_BiTgte_Blend.def("PCurve1OnFillet", (opencascade::handle<Geom2d_Curve> (BiTgte_Blend::*)(const Standard_Integer) const) &BiTgte_Blend::PCurve1OnFillet, "gives the PCurve associated to CurveOnShape1(Index) on the Fillet", py::arg("Index"));
cls_BiTgte_Blend.def("PCurveOnFace2", (opencascade::handle<Geom2d_Curve> (BiTgte_Blend::*)(const Standard_Integer) const) &BiTgte_Blend::PCurveOnFace2, "gives the PCurve associated to CurveOnShape2(Index) on the support face Warning: returns a Null Handle if SupportShape2 is not a Face", py::arg("Index"));
cls_BiTgte_Blend.def("PCurve2OnFillet", (opencascade::handle<Geom2d_Curve> (BiTgte_Blend::*)(const Standard_Integer) const) &BiTgte_Blend::PCurve2OnFillet, "gives the PCurve associated to CurveOnShape2(Index) on the fillet", py::arg("Index"));
cls_BiTgte_Blend.def("NbBranches", (Standard_Integer (BiTgte_Blend::*)()) &BiTgte_Blend::NbBranches, "None");
cls_BiTgte_Blend.def("IndicesOfBranche", [](BiTgte_Blend &self, const Standard_Integer Index, Standard_Integer & From, Standard_Integer & To){ self.IndicesOfBranche(Index, From, To); return std::tuple<Standard_Integer &, Standard_Integer &>(From, To); }, "Set in <From>,<To> the indices of the faces of the branche <Index>.", py::arg("Index"), py::arg("From"), py::arg("To"));
cls_BiTgte_Blend.def("ComputeCenters", (void (BiTgte_Blend::*)()) &BiTgte_Blend::ComputeCenters, "Computes the center lines");

// Enums

}