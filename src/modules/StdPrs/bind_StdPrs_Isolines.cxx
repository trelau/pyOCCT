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
#include <Prs3d_Root.hxx>
#include <Standard_Handle.hxx>
#include <Prs3d_Presentation.hxx>
#include <TopoDS_Face.hxx>
#include <Prs3d_Drawer.hxx>
#include <Standard_TypeDef.hxx>
#include <StdPrs_ToolTriangulatedShape.hxx>
#include <Prs3d_NListOfSequenceOfPnt.hxx>
#include <Poly_Triangulation.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <gp_Pnt.hxx>
#include <StdPrs_Isolines.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Pnt2d.hxx>

void bind_StdPrs_Isolines(py::module &mod){

py::class_<StdPrs_Isolines, Prs3d_Root> cls_StdPrs_Isolines(mod, "StdPrs_Isolines", "Tool for computing isoline representation for a face or surface. Depending on a flags set to the given Prs3d_Drawer instance, on-surface (is used by default) or on-triangulation isoline builder algorithm will be used. If the given shape is not triangulated, on-surface isoline builder will be applied regardless of Prs3d_Drawer flags.");

// Constructors

// Fields

// Methods
cls_StdPrs_Isolines.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const TopoDS_Face &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real)) &StdPrs_Isolines::Add, "Computes isolines presentation for a TopoDS face. This method chooses proper version of isoline builder algorithm : on triangulation or surface depending on the flag passed from Prs3d_Drawer attributes. This method is a default way to display isolines for a given TopoDS face.", py::arg("thePresentation"), py::arg("theFace"), py::arg("theDrawer"), py::arg("theDeflection"));
cls_StdPrs_Isolines.def_static("Add_", (void (*)(const TopoDS_Face &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, Prs3d_NListOfSequenceOfPnt &, Prs3d_NListOfSequenceOfPnt &)) &StdPrs_Isolines::Add, "Computes isolines presentation for a TopoDS face. This method chooses proper version of isoline builder algorithm : on triangulation or surface depending on the flag passed from Prs3d_Drawer attributes. This method is a default way to display isolines for a given TopoDS face.", py::arg("theFace"), py::arg("theDrawer"), py::arg("theDeflection"), py::arg("theUPolylines"), py::arg("theVPolylines"));
cls_StdPrs_Isolines.def_static("AddOnTriangulation_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const TopoDS_Face &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_Isolines::AddOnTriangulation, "Computes isolines on triangulation and adds them to a presentation.", py::arg("thePresentation"), py::arg("theFace"), py::arg("theDrawer"));
cls_StdPrs_Isolines.def_static("AddOnTriangulation_", (void (*)(const TopoDS_Face &, const opencascade::handle<Prs3d_Drawer> &, Prs3d_NListOfSequenceOfPnt &, Prs3d_NListOfSequenceOfPnt &)) &StdPrs_Isolines::AddOnTriangulation, "Computes isolines on triangulation.", py::arg("theFace"), py::arg("theDrawer"), py::arg("theUPolylines"), py::arg("theVPolylines"));
cls_StdPrs_Isolines.def_static("AddOnTriangulation_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Poly_Triangulation> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const opencascade::handle<Prs3d_Drawer> &, const TColStd_SequenceOfReal &, const TColStd_SequenceOfReal &)) &StdPrs_Isolines::AddOnTriangulation, "Computes isolines on triangulation and adds them to a presentation.", py::arg("thePresentation"), py::arg("theTriangulation"), py::arg("theSurface"), py::arg("theLocation"), py::arg("theDrawer"), py::arg("theUIsoParams"), py::arg("theVIsoParams"));
cls_StdPrs_Isolines.def_static("AddOnSurface_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const TopoDS_Face &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real)) &StdPrs_Isolines::AddOnSurface, "Computes isolines on surface and adds them to presentation.", py::arg("thePresentation"), py::arg("theFace"), py::arg("theDrawer"), py::arg("theDeflection"));
cls_StdPrs_Isolines.def_static("AddOnSurface_", (void (*)(const TopoDS_Face &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, Prs3d_NListOfSequenceOfPnt &, Prs3d_NListOfSequenceOfPnt &)) &StdPrs_Isolines::AddOnSurface, "Computes isolines on surface and adds them to presentation.", py::arg("theFace"), py::arg("theDrawer"), py::arg("theDeflection"), py::arg("theUPolylines"), py::arg("theVPolylines"));
cls_StdPrs_Isolines.def_static("AddOnSurface_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TColStd_SequenceOfReal &, const TColStd_SequenceOfReal &)) &StdPrs_Isolines::AddOnSurface, "Computes isolines on surface and adds them to presentation.", py::arg("thePresentation"), py::arg("theSurface"), py::arg("theDrawer"), py::arg("theDeflection"), py::arg("theUIsoParams"), py::arg("theVIsoParams"));
cls_StdPrs_Isolines.def_static("UVIsoParameters_", (void (*)(const TopoDS_Face &, const Standard_Integer, const Standard_Integer, const Standard_Real, TColStd_SequenceOfReal &, TColStd_SequenceOfReal &)) &StdPrs_Isolines::UVIsoParameters, "Evalute sequence of parameters for drawing uv isolines for a given face.", py::arg("theFace"), py::arg("theNbIsoU"), py::arg("theNbIsoV"), py::arg("theUVLimit"), py::arg("theUIsoParams"), py::arg("theVIsoParams"));

// Enums

}