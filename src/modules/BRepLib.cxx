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
#include <BRepLib_EdgeError.hxx>
#include <BRepLib_ShapeModification.hxx>
#include <BRepLib_FaceError.hxx>
#include <BRepLib_ShellError.hxx>
#include <BRepLib_WireError.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepLib_Command.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Edge.hxx>
#include <BRepLib_MakeShape.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Hypr.hxx>
#include <gp_Parab.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Surface.hxx>
#include <BRepLib_MakeEdge.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Parab2d.hxx>
#include <BRepLib_MakeEdge2d.hxx>
#include <gp_Pln.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Cone.hxx>
#include <gp_Sphere.hxx>
#include <gp_Torus.hxx>
#include <TopoDS_Wire.hxx>
#include <BRepLib_MakeFace.hxx>
#include <BRepLib_MakePolygon.hxx>
#include <TopoDS_Shell.hxx>
#include <BRepLib_MakeShell.hxx>
#include <TopoDS_CompSolid.hxx>
#include <TopoDS_Solid.hxx>
#include <BRepLib_MakeSolid.hxx>
#include <BRepLib_MakeVertex.hxx>
#include <NCollection_UBTree.hxx>
#include <Bnd_Box.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <BRepLib_MakeWire.hxx>
#include <NCollection_List.hxx>
#include <NCollection_DataMap.hxx>
#include <Geom_Plane.hxx>
#include <GeomAbs_Shape.hxx>
#include <BRepLib.hxx>
#include <BRepTools_ReShape.hxx>
#include <Adaptor3d_Curve.hxx>
#include <BRepLib_FindSurface.hxx>
#include <BRepLib_FuseEdges.hxx>
#include <BRepLib_CheckCurveOnSurface.hxx>
#include <GeomLib_CheckCurveOnSurface.hxx>
#include <TopLoc_Location.hxx>
#include <TopTools_DataMapOfIntegerListOfShape.hxx>
#include <TopTools_DataMapOfIntegerShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>

PYBIND11_MODULE(BRepLib, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.BRepTools");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.GeomLib");
py::module::import("OCCT.TopLoc");

// ENUM: BREPLIB_EDGEERROR
py::enum_<BRepLib_EdgeError>(mod, "BRepLib_EdgeError", "Errors that can occur at edge construction. no error")
	.value("BRepLib_EdgeDone", BRepLib_EdgeError::BRepLib_EdgeDone)
	.value("BRepLib_PointProjectionFailed", BRepLib_EdgeError::BRepLib_PointProjectionFailed)
	.value("BRepLib_ParameterOutOfRange", BRepLib_EdgeError::BRepLib_ParameterOutOfRange)
	.value("BRepLib_DifferentPointsOnClosedCurve", BRepLib_EdgeError::BRepLib_DifferentPointsOnClosedCurve)
	.value("BRepLib_PointWithInfiniteParameter", BRepLib_EdgeError::BRepLib_PointWithInfiniteParameter)
	.value("BRepLib_DifferentsPointAndParameter", BRepLib_EdgeError::BRepLib_DifferentsPointAndParameter)
	.value("BRepLib_LineThroughIdenticPoints", BRepLib_EdgeError::BRepLib_LineThroughIdenticPoints)
	.export_values();


// ENUM: BREPLIB_SHAPEMODIFICATION
py::enum_<BRepLib_ShapeModification>(mod, "BRepLib_ShapeModification", "Modification type after a topologic operation.")
	.value("BRepLib_Preserved", BRepLib_ShapeModification::BRepLib_Preserved)
	.value("BRepLib_Deleted", BRepLib_ShapeModification::BRepLib_Deleted)
	.value("BRepLib_Trimmed", BRepLib_ShapeModification::BRepLib_Trimmed)
	.value("BRepLib_Merged", BRepLib_ShapeModification::BRepLib_Merged)
	.value("BRepLib_BoundaryModified", BRepLib_ShapeModification::BRepLib_BoundaryModified)
	.export_values();


// ENUM: BREPLIB_FACEERROR
py::enum_<BRepLib_FaceError>(mod, "BRepLib_FaceError", "Errors that can occur at face construction. no error not initialised")
	.value("BRepLib_FaceDone", BRepLib_FaceError::BRepLib_FaceDone)
	.value("BRepLib_NoFace", BRepLib_FaceError::BRepLib_NoFace)
	.value("BRepLib_NotPlanar", BRepLib_FaceError::BRepLib_NotPlanar)
	.value("BRepLib_CurveProjectionFailed", BRepLib_FaceError::BRepLib_CurveProjectionFailed)
	.value("BRepLib_ParametersOutOfRange", BRepLib_FaceError::BRepLib_ParametersOutOfRange)
	.export_values();


// ENUM: BREPLIB_SHELLERROR
py::enum_<BRepLib_ShellError>(mod, "BRepLib_ShellError", "Errors that can occur at shell construction.")
	.value("BRepLib_ShellDone", BRepLib_ShellError::BRepLib_ShellDone)
	.value("BRepLib_EmptyShell", BRepLib_ShellError::BRepLib_EmptyShell)
	.value("BRepLib_DisconnectedShell", BRepLib_ShellError::BRepLib_DisconnectedShell)
	.value("BRepLib_ShellParametersOutOfRange", BRepLib_ShellError::BRepLib_ShellParametersOutOfRange)
	.export_values();


// ENUM: BREPLIB_WIREERROR
py::enum_<BRepLib_WireError>(mod, "BRepLib_WireError", "Errors that can occur at wire construction. no error")
	.value("BRepLib_WireDone", BRepLib_WireError::BRepLib_WireDone)
	.value("BRepLib_EmptyWire", BRepLib_WireError::BRepLib_EmptyWire)
	.value("BRepLib_DisconnectedWire", BRepLib_WireError::BRepLib_DisconnectedWire)
	.value("BRepLib_NonManifoldWire", BRepLib_WireError::BRepLib_NonManifoldWire)
	.export_values();


// CLASS: BREPLIB_COMMAND
py::class_<BRepLib_Command> cls_BRepLib_Command(mod, "BRepLib_Command", "Root class for all commands in BRepLib.");

// Methods
// cls_BRepLib_Command.def_static("operator new_", (void * (*)(size_t)) &BRepLib_Command::operator new, "None", py::arg("theSize"));
// cls_BRepLib_Command.def_static("operator delete_", (void (*)(void *)) &BRepLib_Command::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_Command.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_Command::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_Command.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_Command::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_Command.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_Command::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_Command.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_Command::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_Command.def("IsDone", (Standard_Boolean (BRepLib_Command::*)() const) &BRepLib_Command::IsDone, "None");
cls_BRepLib_Command.def("Check", (void (BRepLib_Command::*)() const) &BRepLib_Command::Check, "Raises NotDone if done is false.");

// CLASS: BREPLIB_MAKESHAPE
py::class_<BRepLib_MakeShape, BRepLib_Command> cls_BRepLib_MakeShape(mod, "BRepLib_MakeShape", "This is the root class for all shape constructions. It stores the result.");

// Methods
// cls_BRepLib_MakeShape.def_static("operator new_", (void * (*)(size_t)) &BRepLib_MakeShape::operator new, "None", py::arg("theSize"));
// cls_BRepLib_MakeShape.def_static("operator delete_", (void (*)(void *)) &BRepLib_MakeShape::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_MakeShape.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_MakeShape::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_MakeShape.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_MakeShape::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_MakeShape.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_MakeShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_MakeShape.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_MakeShape::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_MakeShape.def("Build", (void (BRepLib_MakeShape::*)()) &BRepLib_MakeShape::Build, "This is called by Shape(). It does nothing but may be redefined.");
cls_BRepLib_MakeShape.def("Shape", (const TopoDS_Shape & (BRepLib_MakeShape::*)()) &BRepLib_MakeShape::Shape, "None");
cls_BRepLib_MakeShape.def("FaceStatus", (BRepLib_ShapeModification (BRepLib_MakeShape::*)(const TopoDS_Face &) const) &BRepLib_MakeShape::FaceStatus, "returns the status of the Face after the shape creation.", py::arg("F"));
cls_BRepLib_MakeShape.def("HasDescendants", (Standard_Boolean (BRepLib_MakeShape::*)(const TopoDS_Face &) const) &BRepLib_MakeShape::HasDescendants, "Returns True if the Face generates new topology.", py::arg("F"));
cls_BRepLib_MakeShape.def("DescendantFaces", (const TopTools_ListOfShape & (BRepLib_MakeShape::*)(const TopoDS_Face &)) &BRepLib_MakeShape::DescendantFaces, "returns the list of generated Faces.", py::arg("F"));
cls_BRepLib_MakeShape.def("NbSurfaces", (Standard_Integer (BRepLib_MakeShape::*)() const) &BRepLib_MakeShape::NbSurfaces, "returns the number of surfaces after the shape creation.");
cls_BRepLib_MakeShape.def("NewFaces", (const TopTools_ListOfShape & (BRepLib_MakeShape::*)(const Standard_Integer)) &BRepLib_MakeShape::NewFaces, "Return the faces created for surface I.", py::arg("I"));
cls_BRepLib_MakeShape.def("FacesFromEdges", (const TopTools_ListOfShape & (BRepLib_MakeShape::*)(const TopoDS_Edge &)) &BRepLib_MakeShape::FacesFromEdges, "returns a list of the created faces from the edge <E>.", py::arg("E"));

// CLASS: BREPLIB_MAKEEDGE
py::class_<BRepLib_MakeEdge, BRepLib_MakeShape> cls_BRepLib_MakeEdge(mod, "BRepLib_MakeEdge", "Provides methods to build edges.");

// Constructors
cls_BRepLib_MakeEdge.def(py::init<>());
cls_BRepLib_MakeEdge.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Lin &>(), py::arg("L"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Lin &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Lin &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Lin &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Circ &>(), py::arg("L"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Circ &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Circ &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Circ &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Elips &>(), py::arg("L"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Elips &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Elips &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Elips &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Hypr &>(), py::arg("L"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Hypr &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Hypr &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Hypr &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Parab &>(), py::arg("L"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Parab &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Parab &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Parab &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &>(), py::arg("L"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &>(), py::arg("L"), py::arg("S"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("S"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("S"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("S"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("S"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("S"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));

// Methods
// cls_BRepLib_MakeEdge.def_static("operator new_", (void * (*)(size_t)) &BRepLib_MakeEdge::operator new, "None", py::arg("theSize"));
// cls_BRepLib_MakeEdge.def_static("operator delete_", (void (*)(void *)) &BRepLib_MakeEdge::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_MakeEdge.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_MakeEdge::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_MakeEdge.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_MakeEdge::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_MakeEdge.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_MakeEdge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_MakeEdge.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_MakeEdge::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom_Curve> &)) &BRepLib_MakeEdge::Init, "None", py::arg("C"));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("S"));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const gp_Pnt &, const gp_Pnt &)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopoDS_Vertex &, const TopoDS_Vertex &)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def("Error", (BRepLib_EdgeError (BRepLib_MakeEdge::*)() const) &BRepLib_MakeEdge::Error, "Returns the error description when NotDone.");
cls_BRepLib_MakeEdge.def("Edge", (const TopoDS_Edge & (BRepLib_MakeEdge::*)()) &BRepLib_MakeEdge::Edge, "None");
cls_BRepLib_MakeEdge.def("Vertex1", (const TopoDS_Vertex & (BRepLib_MakeEdge::*)() const) &BRepLib_MakeEdge::Vertex1, "Returns the first vertex of the edge. May be Null.");
cls_BRepLib_MakeEdge.def("Vertex2", (const TopoDS_Vertex & (BRepLib_MakeEdge::*)() const) &BRepLib_MakeEdge::Vertex2, "Returns the second vertex of the edge. May be Null.");

// CLASS: BREPLIB_MAKEEDGE2D
py::class_<BRepLib_MakeEdge2d, BRepLib_MakeShape> cls_BRepLib_MakeEdge2d(mod, "BRepLib_MakeEdge2d", "Provides methods to build edges.");

// Constructors
cls_BRepLib_MakeEdge2d.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge2d.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge2d.def(py::init<const gp_Lin2d &>(), py::arg("L"));
cls_BRepLib_MakeEdge2d.def(py::init<const gp_Lin2d &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge2d.def(py::init<const gp_Lin2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge2d.def(py::init<const gp_Lin2d &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge2d.def(py::init<const gp_Circ2d &>(), py::arg("L"));
cls_BRepLib_MakeEdge2d.def(py::init<const gp_Circ2d &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge2d.def(py::init<const gp_Circ2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge2d.def(py::init<const gp_Circ2d &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge2d.def(py::init<const gp_Elips2d &>(), py::arg("L"));
cls_BRepLib_MakeEdge2d.def(py::init<const gp_Elips2d &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge2d.def(py::init<const gp_Elips2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge2d.def(py::init<const gp_Elips2d &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge2d.def(py::init<const gp_Hypr2d &>(), py::arg("L"));
cls_BRepLib_MakeEdge2d.def(py::init<const gp_Hypr2d &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge2d.def(py::init<const gp_Hypr2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge2d.def(py::init<const gp_Hypr2d &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge2d.def(py::init<const gp_Parab2d &>(), py::arg("L"));
cls_BRepLib_MakeEdge2d.def(py::init<const gp_Parab2d &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge2d.def(py::init<const gp_Parab2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge2d.def(py::init<const gp_Parab2d &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge2d.def(py::init<const opencascade::handle<Geom2d_Curve> &>(), py::arg("L"));
cls_BRepLib_MakeEdge2d.def(py::init<const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge2d.def(py::init<const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge2d.def(py::init<const opencascade::handle<Geom2d_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge2d.def(py::init<const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge2d.def(py::init<const opencascade::handle<Geom2d_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));

// Methods
// cls_BRepLib_MakeEdge2d.def_static("operator new_", (void * (*)(size_t)) &BRepLib_MakeEdge2d::operator new, "None", py::arg("theSize"));
// cls_BRepLib_MakeEdge2d.def_static("operator delete_", (void (*)(void *)) &BRepLib_MakeEdge2d::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_MakeEdge2d.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_MakeEdge2d::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_MakeEdge2d.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_MakeEdge2d::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_MakeEdge2d.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_MakeEdge2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_MakeEdge2d.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_MakeEdge2d::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_MakeEdge2d.def("Init", (void (BRepLib_MakeEdge2d::*)(const opencascade::handle<Geom2d_Curve> &)) &BRepLib_MakeEdge2d::Init, "None", py::arg("C"));
cls_BRepLib_MakeEdge2d.def("Init", (void (BRepLib_MakeEdge2d::*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge2d::Init, "None", py::arg("C"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge2d.def("Init", (void (BRepLib_MakeEdge2d::*)(const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Pnt2d &)) &BRepLib_MakeEdge2d::Init, "None", py::arg("C"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge2d.def("Init", (void (BRepLib_MakeEdge2d::*)(const opencascade::handle<Geom2d_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &)) &BRepLib_MakeEdge2d::Init, "None", py::arg("C"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge2d.def("Init", (void (BRepLib_MakeEdge2d::*)(const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge2d::Init, "None", py::arg("C"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge2d.def("Init", (void (BRepLib_MakeEdge2d::*)(const opencascade::handle<Geom2d_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge2d::Init, "None", py::arg("C"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge2d.def("Error", (BRepLib_EdgeError (BRepLib_MakeEdge2d::*)() const) &BRepLib_MakeEdge2d::Error, "Returns the error description when NotDone.");
cls_BRepLib_MakeEdge2d.def("Edge", (const TopoDS_Edge & (BRepLib_MakeEdge2d::*)()) &BRepLib_MakeEdge2d::Edge, "None");
cls_BRepLib_MakeEdge2d.def("Vertex1", (const TopoDS_Vertex & (BRepLib_MakeEdge2d::*)() const) &BRepLib_MakeEdge2d::Vertex1, "Returns the first vertex of the edge. May be Null.");
cls_BRepLib_MakeEdge2d.def("Vertex2", (const TopoDS_Vertex & (BRepLib_MakeEdge2d::*)() const) &BRepLib_MakeEdge2d::Vertex2, "Returns the second vertex of the edge. May be Null.");

// CLASS: BREPLIB_MAKEFACE
py::class_<BRepLib_MakeFace, BRepLib_MakeShape> cls_BRepLib_MakeFace(mod, "BRepLib_MakeFace", "Provides methods to build faces.");

// Constructors
cls_BRepLib_MakeFace.def(py::init<>());
cls_BRepLib_MakeFace.def(py::init<const TopoDS_Face &>(), py::arg("F"));
cls_BRepLib_MakeFace.def(py::init<const gp_Pln &>(), py::arg("P"));
cls_BRepLib_MakeFace.def(py::init<const gp_Cylinder &>(), py::arg("C"));
cls_BRepLib_MakeFace.def(py::init<const gp_Cone &>(), py::arg("C"));
cls_BRepLib_MakeFace.def(py::init<const gp_Sphere &>(), py::arg("S"));
cls_BRepLib_MakeFace.def(py::init<const gp_Torus &>(), py::arg("C"));
cls_BRepLib_MakeFace.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real>(), py::arg("S"), py::arg("TolDegen"));
cls_BRepLib_MakeFace.def(py::init<const gp_Pln &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepLib_MakeFace.def(py::init<const gp_Cylinder &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepLib_MakeFace.def(py::init<const gp_Cone &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepLib_MakeFace.def(py::init<const gp_Sphere &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepLib_MakeFace.def(py::init<const gp_Torus &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepLib_MakeFace.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("TolDegen"));
cls_BRepLib_MakeFace.def(py::init<const TopoDS_Wire &>(), py::arg("W"));
cls_BRepLib_MakeFace.def(py::init<const TopoDS_Wire &, const Standard_Boolean>(), py::arg("W"), py::arg("OnlyPlane"));
cls_BRepLib_MakeFace.def(py::init<const gp_Pln &, const TopoDS_Wire &>(), py::arg("P"), py::arg("W"));
cls_BRepLib_MakeFace.def(py::init<const gp_Pln &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("P"), py::arg("W"), py::arg("Inside"));
cls_BRepLib_MakeFace.def(py::init<const gp_Cylinder &, const TopoDS_Wire &>(), py::arg("C"), py::arg("W"));
cls_BRepLib_MakeFace.def(py::init<const gp_Cylinder &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("C"), py::arg("W"), py::arg("Inside"));
cls_BRepLib_MakeFace.def(py::init<const gp_Cone &, const TopoDS_Wire &>(), py::arg("C"), py::arg("W"));
cls_BRepLib_MakeFace.def(py::init<const gp_Cone &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("C"), py::arg("W"), py::arg("Inside"));
cls_BRepLib_MakeFace.def(py::init<const gp_Sphere &, const TopoDS_Wire &>(), py::arg("S"), py::arg("W"));
cls_BRepLib_MakeFace.def(py::init<const gp_Sphere &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("S"), py::arg("W"), py::arg("Inside"));
cls_BRepLib_MakeFace.def(py::init<const gp_Torus &, const TopoDS_Wire &>(), py::arg("C"), py::arg("W"));
cls_BRepLib_MakeFace.def(py::init<const gp_Torus &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("C"), py::arg("W"), py::arg("Inside"));
cls_BRepLib_MakeFace.def(py::init<const opencascade::handle<Geom_Surface> &, const TopoDS_Wire &>(), py::arg("S"), py::arg("W"));
cls_BRepLib_MakeFace.def(py::init<const opencascade::handle<Geom_Surface> &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("S"), py::arg("W"), py::arg("Inside"));
cls_BRepLib_MakeFace.def(py::init<const TopoDS_Face &, const TopoDS_Wire &>(), py::arg("F"), py::arg("W"));

// Methods
// cls_BRepLib_MakeFace.def_static("operator new_", (void * (*)(size_t)) &BRepLib_MakeFace::operator new, "None", py::arg("theSize"));
// cls_BRepLib_MakeFace.def_static("operator delete_", (void (*)(void *)) &BRepLib_MakeFace::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_MakeFace.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_MakeFace::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_MakeFace.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_MakeFace::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_MakeFace.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_MakeFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_MakeFace.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_MakeFace::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_MakeFace.def("Init", (void (BRepLib_MakeFace::*)(const TopoDS_Face &)) &BRepLib_MakeFace::Init, "Load the face.", py::arg("F"));
cls_BRepLib_MakeFace.def("Init", (void (BRepLib_MakeFace::*)(const opencascade::handle<Geom_Surface> &, const Standard_Boolean, const Standard_Real)) &BRepLib_MakeFace::Init, "Creates the face from the surface. If Bound is True a wire is made from the natural bounds. Accepts tolerance value (TolDegen) for resolution of degenerated edges.", py::arg("S"), py::arg("Bound"), py::arg("TolDegen"));
cls_BRepLib_MakeFace.def("Init", (void (BRepLib_MakeFace::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepLib_MakeFace::Init, "Creates the face from the surface and the min-max values. Accepts tolerance value (TolDegen) for resolution of degenerated edges.", py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("TolDegen"));
cls_BRepLib_MakeFace.def("Add", (void (BRepLib_MakeFace::*)(const TopoDS_Wire &)) &BRepLib_MakeFace::Add, "Adds the wire <W> in the current face.", py::arg("W"));
cls_BRepLib_MakeFace.def("Error", (BRepLib_FaceError (BRepLib_MakeFace::*)() const) &BRepLib_MakeFace::Error, "None");
cls_BRepLib_MakeFace.def("Face", (const TopoDS_Face & (BRepLib_MakeFace::*)() const) &BRepLib_MakeFace::Face, "Returns the new face.");
cls_BRepLib_MakeFace.def_static("IsDegenerated_", [](const opencascade::handle<Geom_Curve> & theCurve, const Standard_Real theMaxTol, Standard_Real & theActTol){ Standard_Boolean rv = BRepLib_MakeFace::IsDegenerated(theCurve, theMaxTol, theActTol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theActTol); }, "Checks the specified curve is degenerated according to specified tolerance. Returns <theActTol> less than <theMaxTol>, which shows actual tolerance to decide the curve is degenerated. Warning: For internal use of BRepLib_MakeFace and BRepLib_MakeShell.", py::arg("theCurve"), py::arg("theMaxTol"), py::arg("theActTol"));

// CLASS: BREPLIB_MAKEPOLYGON
py::class_<BRepLib_MakePolygon, BRepLib_MakeShape> cls_BRepLib_MakePolygon(mod, "BRepLib_MakePolygon", "Class to build polygonal wires.");

// Constructors
cls_BRepLib_MakePolygon.def(py::init<>());
cls_BRepLib_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_BRepLib_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("Close"));
cls_BRepLib_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"));
cls_BRepLib_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"), py::arg("Close"));
cls_BRepLib_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_BRepLib_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Boolean>(), py::arg("V1"), py::arg("V2"), py::arg("V3"), py::arg("Close"));
cls_BRepLib_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"), py::arg("V3"), py::arg("V4"));
cls_BRepLib_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Boolean>(), py::arg("V1"), py::arg("V2"), py::arg("V3"), py::arg("V4"), py::arg("Close"));

// Methods
// cls_BRepLib_MakePolygon.def_static("operator new_", (void * (*)(size_t)) &BRepLib_MakePolygon::operator new, "None", py::arg("theSize"));
// cls_BRepLib_MakePolygon.def_static("operator delete_", (void (*)(void *)) &BRepLib_MakePolygon::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_MakePolygon.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_MakePolygon::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_MakePolygon.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_MakePolygon::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_MakePolygon.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_MakePolygon::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_MakePolygon.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_MakePolygon::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_MakePolygon.def("Add", (void (BRepLib_MakePolygon::*)(const gp_Pnt &)) &BRepLib_MakePolygon::Add, "None", py::arg("P"));
cls_BRepLib_MakePolygon.def("Add", (void (BRepLib_MakePolygon::*)(const TopoDS_Vertex &)) &BRepLib_MakePolygon::Add, "None", py::arg("V"));
cls_BRepLib_MakePolygon.def("Added", (Standard_Boolean (BRepLib_MakePolygon::*)() const) &BRepLib_MakePolygon::Added, "Returns True if the last vertex or point was succesfully added.");
cls_BRepLib_MakePolygon.def("Close", (void (BRepLib_MakePolygon::*)()) &BRepLib_MakePolygon::Close, "None");
cls_BRepLib_MakePolygon.def("FirstVertex", (const TopoDS_Vertex & (BRepLib_MakePolygon::*)() const) &BRepLib_MakePolygon::FirstVertex, "None");
cls_BRepLib_MakePolygon.def("LastVertex", (const TopoDS_Vertex & (BRepLib_MakePolygon::*)() const) &BRepLib_MakePolygon::LastVertex, "None");
cls_BRepLib_MakePolygon.def("Edge", (const TopoDS_Edge & (BRepLib_MakePolygon::*)() const) &BRepLib_MakePolygon::Edge, "Returns the last edge added to the polygon.");
cls_BRepLib_MakePolygon.def("Wire", (const TopoDS_Wire & (BRepLib_MakePolygon::*)()) &BRepLib_MakePolygon::Wire, "None");

// CLASS: BREPLIB_MAKESHELL
py::class_<BRepLib_MakeShell, BRepLib_MakeShape> cls_BRepLib_MakeShell(mod, "BRepLib_MakeShell", "Provides methos to build shells.");

// Constructors
cls_BRepLib_MakeShell.def(py::init<>());
cls_BRepLib_MakeShell.def(py::init<const opencascade::handle<Geom_Surface> &>(), py::arg("S"));
cls_BRepLib_MakeShell.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Boolean>(), py::arg("S"), py::arg("Segment"));
cls_BRepLib_MakeShell.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepLib_MakeShell.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Segment"));

// Methods
// cls_BRepLib_MakeShell.def_static("operator new_", (void * (*)(size_t)) &BRepLib_MakeShell::operator new, "None", py::arg("theSize"));
// cls_BRepLib_MakeShell.def_static("operator delete_", (void (*)(void *)) &BRepLib_MakeShell::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_MakeShell.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_MakeShell::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_MakeShell.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_MakeShell::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_MakeShell.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_MakeShell::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_MakeShell.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_MakeShell::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_MakeShell.def("Init", [](BRepLib_MakeShell &self, const opencascade::handle<Geom_Surface> & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_BRepLib_MakeShell.def("Init", (void (BRepLib_MakeShell::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &BRepLib_MakeShell::Init, "Creates the shell from the surface and the min-max values.", py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Segment"));
cls_BRepLib_MakeShell.def("Error", (BRepLib_ShellError (BRepLib_MakeShell::*)() const) &BRepLib_MakeShell::Error, "None");
cls_BRepLib_MakeShell.def("Shell", (const TopoDS_Shell & (BRepLib_MakeShell::*)() const) &BRepLib_MakeShell::Shell, "Returns the new Shell.");

// CLASS: BREPLIB_MAKESOLID
py::class_<BRepLib_MakeSolid, BRepLib_MakeShape> cls_BRepLib_MakeSolid(mod, "BRepLib_MakeSolid", "Makes a solid from compsolid or shells.");

// Constructors
cls_BRepLib_MakeSolid.def(py::init<>());
cls_BRepLib_MakeSolid.def(py::init<const TopoDS_CompSolid &>(), py::arg("S"));
cls_BRepLib_MakeSolid.def(py::init<const TopoDS_Shell &>(), py::arg("S"));
cls_BRepLib_MakeSolid.def(py::init<const TopoDS_Shell &, const TopoDS_Shell &>(), py::arg("S1"), py::arg("S2"));
cls_BRepLib_MakeSolid.def(py::init<const TopoDS_Shell &, const TopoDS_Shell &, const TopoDS_Shell &>(), py::arg("S1"), py::arg("S2"), py::arg("S3"));
cls_BRepLib_MakeSolid.def(py::init<const TopoDS_Solid &>(), py::arg("So"));
cls_BRepLib_MakeSolid.def(py::init<const TopoDS_Solid &, const TopoDS_Shell &>(), py::arg("So"), py::arg("S"));

// Methods
// cls_BRepLib_MakeSolid.def_static("operator new_", (void * (*)(size_t)) &BRepLib_MakeSolid::operator new, "None", py::arg("theSize"));
// cls_BRepLib_MakeSolid.def_static("operator delete_", (void (*)(void *)) &BRepLib_MakeSolid::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_MakeSolid.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_MakeSolid::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_MakeSolid.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_MakeSolid::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_MakeSolid.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_MakeSolid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_MakeSolid.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_MakeSolid::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_MakeSolid.def("Add", (void (BRepLib_MakeSolid::*)(const TopoDS_Shell &)) &BRepLib_MakeSolid::Add, "Add the shell to the current solid.", py::arg("S"));
cls_BRepLib_MakeSolid.def("Solid", (const TopoDS_Solid & (BRepLib_MakeSolid::*)()) &BRepLib_MakeSolid::Solid, "Returns the new Solid.");
cls_BRepLib_MakeSolid.def("FaceStatus", (BRepLib_ShapeModification (BRepLib_MakeSolid::*)(const TopoDS_Face &) const) &BRepLib_MakeSolid::FaceStatus, "returns the status of the Face after the shape creation.", py::arg("F"));

// CLASS: BREPLIB_MAKEVERTEX
py::class_<BRepLib_MakeVertex, BRepLib_MakeShape> cls_BRepLib_MakeVertex(mod, "BRepLib_MakeVertex", "Provides methods to build vertices.");

// Constructors
cls_BRepLib_MakeVertex.def(py::init<const gp_Pnt &>(), py::arg("P"));

// Methods
// cls_BRepLib_MakeVertex.def_static("operator new_", (void * (*)(size_t)) &BRepLib_MakeVertex::operator new, "None", py::arg("theSize"));
// cls_BRepLib_MakeVertex.def_static("operator delete_", (void (*)(void *)) &BRepLib_MakeVertex::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_MakeVertex.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_MakeVertex::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_MakeVertex.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_MakeVertex::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_MakeVertex.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_MakeVertex::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_MakeVertex.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_MakeVertex::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_MakeVertex.def("Vertex", (const TopoDS_Vertex & (BRepLib_MakeVertex::*)()) &BRepLib_MakeVertex::Vertex, "None");

// CLASS: BREPLIB_MAKEWIRE
py::class_<BRepLib_MakeWire, BRepLib_MakeShape> cls_BRepLib_MakeWire(mod, "BRepLib_MakeWire", "Provides methods to build wires.");

// Constructors
cls_BRepLib_MakeWire.def(py::init<>());
cls_BRepLib_MakeWire.def(py::init<const TopoDS_Edge &>(), py::arg("E"));
cls_BRepLib_MakeWire.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("E1"), py::arg("E2"));
cls_BRepLib_MakeWire.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("E1"), py::arg("E2"), py::arg("E3"));
cls_BRepLib_MakeWire.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("E1"), py::arg("E2"), py::arg("E3"), py::arg("E4"));
cls_BRepLib_MakeWire.def(py::init<const TopoDS_Wire &>(), py::arg("W"));
cls_BRepLib_MakeWire.def(py::init<const TopoDS_Wire &, const TopoDS_Edge &>(), py::arg("W"), py::arg("E"));

// Methods
// cls_BRepLib_MakeWire.def_static("operator new_", (void * (*)(size_t)) &BRepLib_MakeWire::operator new, "None", py::arg("theSize"));
// cls_BRepLib_MakeWire.def_static("operator delete_", (void (*)(void *)) &BRepLib_MakeWire::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_MakeWire.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_MakeWire::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_MakeWire.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_MakeWire::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_MakeWire.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_MakeWire::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_MakeWire.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_MakeWire::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_MakeWire.def("Add", (void (BRepLib_MakeWire::*)(const TopoDS_Edge &)) &BRepLib_MakeWire::Add, "Add the edge <E> to the current wire.", py::arg("E"));
cls_BRepLib_MakeWire.def("Add", (void (BRepLib_MakeWire::*)(const TopoDS_Wire &)) &BRepLib_MakeWire::Add, "Add the edges of <W> to the current wire.", py::arg("W"));
cls_BRepLib_MakeWire.def("Add", (void (BRepLib_MakeWire::*)(const TopTools_ListOfShape &)) &BRepLib_MakeWire::Add, "Add the edges of <L> to the current wire. The edges are not to be consecutive. But they are to be all connected geometrically or topologically.", py::arg("L"));
cls_BRepLib_MakeWire.def("Error", (BRepLib_WireError (BRepLib_MakeWire::*)() const) &BRepLib_MakeWire::Error, "None");
cls_BRepLib_MakeWire.def("Wire", (const TopoDS_Wire & (BRepLib_MakeWire::*)()) &BRepLib_MakeWire::Wire, "Returns the new wire.");
cls_BRepLib_MakeWire.def("Edge", (const TopoDS_Edge & (BRepLib_MakeWire::*)() const) &BRepLib_MakeWire::Edge, "Returns the last edge added to the wire.");
cls_BRepLib_MakeWire.def("Vertex", (const TopoDS_Vertex & (BRepLib_MakeWire::*)() const) &BRepLib_MakeWire::Vertex, "Returns the last connecting vertex.");

// CLASS: BREPLIB
py::class_<BRepLib> cls_BRepLib(mod, "BRepLib", "The BRepLib package provides general utilities for BRep.");

// Methods
// cls_BRepLib.def_static("operator new_", (void * (*)(size_t)) &BRepLib::operator new, "None", py::arg("theSize"));
// cls_BRepLib.def_static("operator delete_", (void (*)(void *)) &BRepLib::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib::operator new[], "None", py::arg("theSize"));
// cls_BRepLib.def_static("operator delete[]_", (void (*)(void *)) &BRepLib::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib.def_static("Precision_", (void (*)(const Standard_Real)) &BRepLib::Precision, "Computes the max distance between edge and its 2d representation on the face. Sets the default precision. The current Precision is returned.", py::arg("P"));
cls_BRepLib.def_static("Precision_", (Standard_Real (*)()) &BRepLib::Precision, "Returns the default precision.");
cls_BRepLib.def_static("Plane_", (void (*)(const opencascade::handle<Geom_Plane> &)) &BRepLib::Plane, "Sets the current plane to P.", py::arg("P"));
cls_BRepLib.def_static("Plane_", (const opencascade::handle<Geom_Plane> & (*)()) &BRepLib::Plane, "Returns the current plane.");
cls_BRepLib.def_static("CheckSameRange_", [](const TopoDS_Edge & a0) -> Standard_Boolean { return BRepLib::CheckSameRange(a0); });
cls_BRepLib.def_static("CheckSameRange_", (Standard_Boolean (*)(const TopoDS_Edge &, const Standard_Real)) &BRepLib::CheckSameRange, "checks if the Edge is same range IGNORING the same range flag of the edge Confusion argument is to compare real numbers idenpendently of any model space tolerance", py::arg("E"), py::arg("Confusion"));
cls_BRepLib.def_static("SameRange_", [](const TopoDS_Edge & a0) -> void { return BRepLib::SameRange(a0); });
cls_BRepLib.def_static("SameRange_", (void (*)(const TopoDS_Edge &, const Standard_Real)) &BRepLib::SameRange, "will make all the curve representation have the same range domain for the parameters. This will IGNORE the same range flag value to proceed. If there is a 3D curve there it will the range of that curve. If not the first curve representation encountered in the list will give its range to the all the other curves.", py::arg("E"), py::arg("Tolerance"));
cls_BRepLib.def_static("BuildCurve3d_", [](const TopoDS_Edge & a0) -> Standard_Boolean { return BRepLib::BuildCurve3d(a0); });
cls_BRepLib.def_static("BuildCurve3d_", [](const TopoDS_Edge & a0, const Standard_Real a1) -> Standard_Boolean { return BRepLib::BuildCurve3d(a0, a1); });
cls_BRepLib.def_static("BuildCurve3d_", [](const TopoDS_Edge & a0, const Standard_Real a1, const GeomAbs_Shape a2) -> Standard_Boolean { return BRepLib::BuildCurve3d(a0, a1, a2); });
cls_BRepLib.def_static("BuildCurve3d_", [](const TopoDS_Edge & a0, const Standard_Real a1, const GeomAbs_Shape a2, const Standard_Integer a3) -> Standard_Boolean { return BRepLib::BuildCurve3d(a0, a1, a2, a3); });
cls_BRepLib.def_static("BuildCurve3d_", (Standard_Boolean (*)(const TopoDS_Edge &, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer)) &BRepLib::BuildCurve3d, "Computes the 3d curve for the edge <E> if it does not exist. Returns True if the curve was computed or existed. Returns False if there is no planar pcurve or the computation failed. <MaxSegment> >= 30 in approximation", py::arg("E"), py::arg("Tolerance"), py::arg("Continuity"), py::arg("MaxDegree"), py::arg("MaxSegment"));
cls_BRepLib.def_static("BuildCurves3d_", [](const TopoDS_Shape & a0, const Standard_Real a1) -> Standard_Boolean { return BRepLib::BuildCurves3d(a0, a1); });
cls_BRepLib.def_static("BuildCurves3d_", [](const TopoDS_Shape & a0, const Standard_Real a1, const GeomAbs_Shape a2) -> Standard_Boolean { return BRepLib::BuildCurves3d(a0, a1, a2); });
cls_BRepLib.def_static("BuildCurves3d_", [](const TopoDS_Shape & a0, const Standard_Real a1, const GeomAbs_Shape a2, const Standard_Integer a3) -> Standard_Boolean { return BRepLib::BuildCurves3d(a0, a1, a2, a3); });
cls_BRepLib.def_static("BuildCurves3d_", (Standard_Boolean (*)(const TopoDS_Shape &, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer)) &BRepLib::BuildCurves3d, "Computes the 3d curves for all the edges of <S> return False if one of the computation failed. <MaxSegment> >= 30 in approximation", py::arg("S"), py::arg("Tolerance"), py::arg("Continuity"), py::arg("MaxDegree"), py::arg("MaxSegment"));
cls_BRepLib.def_static("BuildCurves3d_", (Standard_Boolean (*)(const TopoDS_Shape &)) &BRepLib::BuildCurves3d, "Computes the 3d curves for all the edges of <S> return False if one of the computation failed.", py::arg("S"));
cls_BRepLib.def_static("BuildPCurveForEdgeOnPlane_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepLib::BuildPCurveForEdgeOnPlane, "Builds pcurve of edge on face if the surface is plane, and updates the edge.", py::arg("theE"), py::arg("theF"));
cls_BRepLib.def_static("BuildPCurveForEdgeOnPlane_", [](const TopoDS_Edge & theE, const TopoDS_Face & theF, opencascade::handle<Geom2d_Curve> & aC2D, Standard_Boolean & bToUpdate){ BRepLib::BuildPCurveForEdgeOnPlane(theE, theF, aC2D, bToUpdate); return bToUpdate; }, "Builds pcurve of edge on face if the surface is plane, but does not update the edge. The output are the pcurve and the flag telling that pcurve was built.", py::arg("theE"), py::arg("theF"), py::arg("aC2D"), py::arg("bToUpdate"));
cls_BRepLib.def_static("UpdateEdgeTol_", (Standard_Boolean (*)(const TopoDS_Edge &, const Standard_Real, const Standard_Real)) &BRepLib::UpdateEdgeTol, "Checks if the edge has a Tolerance smaller than -- -- -- -- MaxToleranceToCheck if so it will compute the radius of -- the cylindrical pipe surface that MinToleranceRequest is the minimum tolerance before it is usefull to start testing. Usually it should be arround 10e-5 contains all -- the curve represenation of the edge returns True if the Edge tolerance had to be updated", py::arg("E"), py::arg("MinToleranceRequest"), py::arg("MaxToleranceToCheck"));
cls_BRepLib.def_static("UpdateEdgeTolerance_", (Standard_Boolean (*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real)) &BRepLib::UpdateEdgeTolerance, "-- Checks all the edges of the shape whose -- -- -- Tolerance is smaller than MaxToleranceToCheck -- Returns True if at least one edge was updated -- MinToleranceRequest is the minimum tolerance before -- it -- is usefull to start testing. Usually it should be arround -- 10e-5--", py::arg("S"), py::arg("MinToleranceRequest"), py::arg("MaxToleranceToCheck"));
cls_BRepLib.def_static("SameParameter_", [](const TopoDS_Edge & a0) -> void { return BRepLib::SameParameter(a0); });
cls_BRepLib.def_static("SameParameter_", (void (*)(const TopoDS_Edge &, const Standard_Real)) &BRepLib::SameParameter, "Computes new 2d curve(s) for the edge <theEdge> to have the same parameter as the 3d curve. The algorithm is not done if the flag SameParameter was True on the Edge.", py::arg("theEdge"), py::arg("Tolerance"));
cls_BRepLib.def_static("SameParameter_", [](const TopoDS_Edge & theEdge, const Standard_Real theTolerance, Standard_Real & theNewTol, const Standard_Boolean IsUseOldEdge){ TopoDS_Edge rv = BRepLib::SameParameter(theEdge, theTolerance, theNewTol, IsUseOldEdge); return std::tuple<TopoDS_Edge, Standard_Real &>(rv, theNewTol); }, "Computes new 2d curve(s) for the edge <theEdge> to have the same parameter as the 3d curve. The algorithm is not done if the flag SameParameter was True on the Edge. theNewTol is a new tolerance of vertices of the input edge (not applied inside the algorithm, but pre-computed). If IsUseOldEdge is true then the input edge will be modified, otherwise the new copy of input edge will be created. Returns the new edge as a result, can be ignored if IsUseOldEdge is true.", py::arg("theEdge"), py::arg("theTolerance"), py::arg("theNewTol"), py::arg("IsUseOldEdge"));
cls_BRepLib.def_static("SameParameter_", [](const TopoDS_Shape & a0) -> void { return BRepLib::SameParameter(a0); });
cls_BRepLib.def_static("SameParameter_", [](const TopoDS_Shape & a0, const Standard_Real a1) -> void { return BRepLib::SameParameter(a0, a1); });
cls_BRepLib.def_static("SameParameter_", (void (*)(const TopoDS_Shape &, const Standard_Real, const Standard_Boolean)) &BRepLib::SameParameter, "Computes new 2d curve(s) for all the edges of <S> to have the same parameter as the 3d curve. The algorithm is not done if the flag SameParameter was True on an Edge.", py::arg("S"), py::arg("Tolerance"), py::arg("forced"));
cls_BRepLib.def_static("SameParameter_", [](const TopoDS_Shape & a0, BRepTools_ReShape & a1) -> void { return BRepLib::SameParameter(a0, a1); });
cls_BRepLib.def_static("SameParameter_", [](const TopoDS_Shape & a0, BRepTools_ReShape & a1, const Standard_Real a2) -> void { return BRepLib::SameParameter(a0, a1, a2); });
cls_BRepLib.def_static("SameParameter_", (void (*)(const TopoDS_Shape &, BRepTools_ReShape &, const Standard_Real, const Standard_Boolean)) &BRepLib::SameParameter, "Computes new 2d curve(s) for all the edges of <S> to have the same parameter as the 3d curve. The algorithm is not done if the flag SameParameter was True on an Edge. theReshaper is used to record the modifications of input shape <S> to prevent any modifications on the shape itself. Thus the input shape (and its subshapes) will not be modified, instead the reshaper will contain a modified empty-copies of original subshapes as substitutions.", py::arg("S"), py::arg("theReshaper"), py::arg("Tolerance"), py::arg("forced"));
cls_BRepLib.def_static("UpdateTolerances_", [](const TopoDS_Shape & a0) -> void { return BRepLib::UpdateTolerances(a0); });
cls_BRepLib.def_static("UpdateTolerances_", (void (*)(const TopoDS_Shape &, const Standard_Boolean)) &BRepLib::UpdateTolerances, "Replaces tolerance of FACE EDGE VERTEX by the tolerance Max of their connected handling shapes. It is not necessary to use this call after SameParameter. (called in)", py::arg("S"), py::arg("verifyFaceTolerance"));
cls_BRepLib.def_static("UpdateTolerances_", [](const TopoDS_Shape & a0, BRepTools_ReShape & a1) -> void { return BRepLib::UpdateTolerances(a0, a1); });
cls_BRepLib.def_static("UpdateTolerances_", (void (*)(const TopoDS_Shape &, BRepTools_ReShape &, const Standard_Boolean)) &BRepLib::UpdateTolerances, "Replaces tolerance of FACE EDGE VERTEX by the tolerance Max of their connected handling shapes. It is not necessary to use this call after SameParameter. (called in) theReshaper is used to record the modifications of input shape <S> to prevent any modifications on the shape itself. Thus the input shape (and its subshapes) will not be modified, instead the reshaper will contain a modified empty-copies of original subshapes as substitutions.", py::arg("S"), py::arg("theReshaper"), py::arg("verifyFaceTolerance"));
cls_BRepLib.def_static("UpdateInnerTolerances_", (void (*)(const TopoDS_Shape &)) &BRepLib::UpdateInnerTolerances, "Checks tolerances of edges (including inner points) and vertices of a shape and updates them to satisfy 'SameParameter' condition", py::arg("S"));
cls_BRepLib.def_static("OrientClosedSolid_", (Standard_Boolean (*)(TopoDS_Solid &)) &BRepLib::OrientClosedSolid, "Orients the solid forward and the shell with the orientation to have matter in the solid. Returns False if the solid is unOrientable (open or incoherent)", py::arg("solid"));
cls_BRepLib.def_static("EncodeRegularity_", [](const TopoDS_Shape & a0) -> void { return BRepLib::EncodeRegularity(a0); });
cls_BRepLib.def_static("EncodeRegularity_", (void (*)(const TopoDS_Shape &, const Standard_Real)) &BRepLib::EncodeRegularity, "Encodes the Regularity of edges on a Shape. Warning: <TolAng> is an angular tolerance, expressed in Rad. Warning: If the edges's regularity are coded before, nothing is done.", py::arg("S"), py::arg("TolAng"));
cls_BRepLib.def_static("EncodeRegularity_", [](const TopoDS_Shape & a0, const TopTools_ListOfShape & a1) -> void { return BRepLib::EncodeRegularity(a0, a1); });
cls_BRepLib.def_static("EncodeRegularity_", (void (*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const Standard_Real)) &BRepLib::EncodeRegularity, "Encodes the Regularity of edges in list <LE> on the shape <S> Warning: <TolAng> is an angular tolerance, expressed in Rad. Warning: If the edges's regularity are coded before, nothing is done.", py::arg("S"), py::arg("LE"), py::arg("TolAng"));
cls_BRepLib.def_static("EncodeRegularity_", [](TopoDS_Edge & a0, const TopoDS_Face & a1, const TopoDS_Face & a2) -> void { return BRepLib::EncodeRegularity(a0, a1, a2); });
cls_BRepLib.def_static("EncodeRegularity_", (void (*)(TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, const Standard_Real)) &BRepLib::EncodeRegularity, "Encodes the Regularity beetween <F1> and <F2> by <E> Warning: <TolAng> is an angular tolerance, expressed in Rad. Warning: If the edge's regularity is coded before, nothing is done.", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("TolAng"));
cls_BRepLib.def_static("SortFaces_", (void (*)(const TopoDS_Shape &, TopTools_ListOfShape &)) &BRepLib::SortFaces, "Sorts in LF the Faces of S on the complexity of their surfaces (Plane,Cylinder,Cone,Sphere,Torus,other)", py::arg("S"), py::arg("LF"));
cls_BRepLib.def_static("ReverseSortFaces_", (void (*)(const TopoDS_Shape &, TopTools_ListOfShape &)) &BRepLib::ReverseSortFaces, "Sorts in LF the Faces of S on the reverse complexity of their surfaces (other,Torus,Sphere,Cone,Cylinder,Plane)", py::arg("S"), py::arg("LF"));
cls_BRepLib.def_static("EnsureNormalConsistency_", [](const TopoDS_Shape & a0) -> Standard_Boolean { return BRepLib::EnsureNormalConsistency(a0); });
cls_BRepLib.def_static("EnsureNormalConsistency_", [](const TopoDS_Shape & a0, const Standard_Real a1) -> Standard_Boolean { return BRepLib::EnsureNormalConsistency(a0, a1); });
cls_BRepLib.def_static("EnsureNormalConsistency_", (Standard_Boolean (*)(const TopoDS_Shape &, const Standard_Real, const Standard_Boolean)) &BRepLib::EnsureNormalConsistency, "Corrects the normals in Poly_Triangulation of faces, in such way that normals at nodes lying along smooth edges have the same value on both adjacent triangulations. Returns TRUE if any correction is done.", py::arg("S"), py::arg("theAngTol"), py::arg("ForceComputeNormals"));
cls_BRepLib.def_static("BoundingVertex_", [](const NCollection_List<TopoDS_Shape> & theLV, gp_Pnt & theNewCenter, Standard_Real & theNewTol){ BRepLib::BoundingVertex(theLV, theNewCenter, theNewTol); return theNewTol; }, "Calculates the bounding sphere around the set of vertexes from the theLV list. Returns the center (theNewCenter) and the radius (theNewTol) of this sphere. This can be used to construct the new vertex which covers the given set of other vertices.", py::arg("theLV"), py::arg("theNewCenter"), py::arg("theNewTol"));
cls_BRepLib.def_static("FindValidRange_", [](const Adaptor3d_Curve & theCurve, const Standard_Real theTolE, const Standard_Real theParV1, const gp_Pnt & thePntV1, const Standard_Real theTolV1, const Standard_Real theParV2, const gp_Pnt & thePntV2, const Standard_Real theTolV2, Standard_Real & theFirst, Standard_Real & theLast){ Standard_Boolean rv = BRepLib::FindValidRange(theCurve, theTolE, theParV1, thePntV1, theTolV1, theParV2, thePntV2, theTolV2, theFirst, theLast); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, theFirst, theLast); }, "For an edge defined by 3d curve and tolerance and vertices defined by points, parameters on curve and tolerances, finds a range of curve between vertices not covered by vertices tolerances. Returns false if there is no such range. Otherwise, sets theFirst and theLast as its bounds.", py::arg("theCurve"), py::arg("theTolE"), py::arg("theParV1"), py::arg("thePntV1"), py::arg("theTolV1"), py::arg("theParV2"), py::arg("thePntV2"), py::arg("theTolV2"), py::arg("theFirst"), py::arg("theLast"));
cls_BRepLib.def_static("FindValidRange_", [](const TopoDS_Edge & theEdge, Standard_Real & theFirst, Standard_Real & theLast){ Standard_Boolean rv = BRepLib::FindValidRange(theEdge, theFirst, theLast); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, theFirst, theLast); }, "Finds a range of 3d curve of the edge not covered by vertices tolerances. Returns false if there is no such range. Otherwise, sets theFirst and theLast as its bounds.", py::arg("theEdge"), py::arg("theFirst"), py::arg("theLast"));
cls_BRepLib.def_static("ExtendFace_", (void (*)(const TopoDS_Face &, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, TopoDS_Face &)) &BRepLib::ExtendFace, "Enlarges the face on the given value.", py::arg("theF"), py::arg("theExtVal"), py::arg("theExtUMin"), py::arg("theExtUMax"), py::arg("theExtVMin"), py::arg("theExtVMax"), py::arg("theFExtended"));

// CLASS: BREPLIB_CHECKCURVEONSURFACE
py::class_<BRepLib_CheckCurveOnSurface> cls_BRepLib_CheckCurveOnSurface(mod, "BRepLib_CheckCurveOnSurface", "Computes the max distance between edge and its 2d representation on the face.");

// Constructors
cls_BRepLib_CheckCurveOnSurface.def(py::init<>());
cls_BRepLib_CheckCurveOnSurface.def(py::init<const TopoDS_Edge &, const TopoDS_Face &>(), py::arg("theEdge"), py::arg("theFace"));

// Methods
// cls_BRepLib_CheckCurveOnSurface.def_static("operator new_", (void * (*)(size_t)) &BRepLib_CheckCurveOnSurface::operator new, "None", py::arg("theSize"));
// cls_BRepLib_CheckCurveOnSurface.def_static("operator delete_", (void (*)(void *)) &BRepLib_CheckCurveOnSurface::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_CheckCurveOnSurface.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_CheckCurveOnSurface::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_CheckCurveOnSurface.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_CheckCurveOnSurface::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_CheckCurveOnSurface.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_CheckCurveOnSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_CheckCurveOnSurface.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_CheckCurveOnSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_CheckCurveOnSurface.def("Init", (void (BRepLib_CheckCurveOnSurface::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepLib_CheckCurveOnSurface::Init, "Sets the data for the algorithm", py::arg("theEdge"), py::arg("theFace"));
cls_BRepLib_CheckCurveOnSurface.def("Perform", [](BRepLib_CheckCurveOnSurface &self) -> void { return self.Perform(); });
cls_BRepLib_CheckCurveOnSurface.def("Perform", (void (BRepLib_CheckCurveOnSurface::*)(const Standard_Boolean)) &BRepLib_CheckCurveOnSurface::Perform, "Performs the calculation If isTheMultyTheadDisabled == TRUE then computation will be made without any parallelization.", py::arg("isTheMultyTheradDisabled"));
cls_BRepLib_CheckCurveOnSurface.def("Curve", (const opencascade::handle<Geom_Curve> & (BRepLib_CheckCurveOnSurface::*)() const) &BRepLib_CheckCurveOnSurface::Curve, "Returns source 3D-Curve");
cls_BRepLib_CheckCurveOnSurface.def("PCurve", (const opencascade::handle<Geom2d_Curve> & (BRepLib_CheckCurveOnSurface::*)() const) &BRepLib_CheckCurveOnSurface::PCurve, "Returns mine 2D-Curve");
cls_BRepLib_CheckCurveOnSurface.def("PCurve2", (const opencascade::handle<Geom2d_Curve> & (BRepLib_CheckCurveOnSurface::*)() const) &BRepLib_CheckCurveOnSurface::PCurve2, "Returns 2nd 2D-Curve (if it exists, e.g. for seam-edge)");
cls_BRepLib_CheckCurveOnSurface.def("Surface", (const opencascade::handle<Geom_Surface> & (BRepLib_CheckCurveOnSurface::*)() const) &BRepLib_CheckCurveOnSurface::Surface, "Returns source surface");
cls_BRepLib_CheckCurveOnSurface.def("Range", [](BRepLib_CheckCurveOnSurface &self, Standard_Real & theFirst, Standard_Real & theLast){ self.Range(theFirst, theLast); return std::tuple<Standard_Real &, Standard_Real &>(theFirst, theLast); }, "Returns first and last parameter of the curves (2D- and 3D-curves are considered to have same range)", py::arg("theFirst"), py::arg("theLast"));
cls_BRepLib_CheckCurveOnSurface.def("IsDone", (Standard_Boolean (BRepLib_CheckCurveOnSurface::*)() const) &BRepLib_CheckCurveOnSurface::IsDone, "Returns true if the max distance has been found");
cls_BRepLib_CheckCurveOnSurface.def("ErrorStatus", (Standard_Integer (BRepLib_CheckCurveOnSurface::*)() const) &BRepLib_CheckCurveOnSurface::ErrorStatus, "Returns error status The possible values are: 0 - OK; 1 - null curve or surface or 2d curve; 2 - invalid parametric range; 3 - error in calculations.");
cls_BRepLib_CheckCurveOnSurface.def("MaxDistance", (Standard_Real (BRepLib_CheckCurveOnSurface::*)() const) &BRepLib_CheckCurveOnSurface::MaxDistance, "Returns max distance");
cls_BRepLib_CheckCurveOnSurface.def("MaxParameter", (Standard_Real (BRepLib_CheckCurveOnSurface::*)() const) &BRepLib_CheckCurveOnSurface::MaxParameter, "Returns parameter in which the distance is maximal");

// CLASS: BREPLIB_FINDSURFACE
py::class_<BRepLib_FindSurface> cls_BRepLib_FindSurface(mod, "BRepLib_FindSurface", "Provides an algorithm to find a Surface through a set of edges.");

// Constructors
cls_BRepLib_FindSurface.def(py::init<>());
cls_BRepLib_FindSurface.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_BRepLib_FindSurface.def(py::init<const TopoDS_Shape &, const Standard_Real>(), py::arg("S"), py::arg("Tol"));
cls_BRepLib_FindSurface.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean>(), py::arg("S"), py::arg("Tol"), py::arg("OnlyPlane"));
cls_BRepLib_FindSurface.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("Tol"), py::arg("OnlyPlane"), py::arg("OnlyClosed"));

// Methods
// cls_BRepLib_FindSurface.def_static("operator new_", (void * (*)(size_t)) &BRepLib_FindSurface::operator new, "None", py::arg("theSize"));
// cls_BRepLib_FindSurface.def_static("operator delete_", (void (*)(void *)) &BRepLib_FindSurface::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_FindSurface.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_FindSurface::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_FindSurface.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_FindSurface::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_FindSurface.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_FindSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_FindSurface.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_FindSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_FindSurface.def("Init", [](BRepLib_FindSurface &self, const TopoDS_Shape & a0) -> void { return self.Init(a0); });
cls_BRepLib_FindSurface.def("Init", [](BRepLib_FindSurface &self, const TopoDS_Shape & a0, const Standard_Real a1) -> void { return self.Init(a0, a1); });
cls_BRepLib_FindSurface.def("Init", [](BRepLib_FindSurface &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Boolean a2) -> void { return self.Init(a0, a1, a2); });
cls_BRepLib_FindSurface.def("Init", (void (BRepLib_FindSurface::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &BRepLib_FindSurface::Init, "Computes the Surface from the edges of <S> with the given tolerance. if <OnlyPlane> is true, the computed surface will be a plane. If it is not possible to find a plane, the flag NotDone will be set. If <OnlyClosed> is true, then S sould be a wire and the existing surface, on which wire S is not closed in 2D, will be ignored.", py::arg("S"), py::arg("Tol"), py::arg("OnlyPlane"), py::arg("OnlyClosed"));
cls_BRepLib_FindSurface.def("Found", (Standard_Boolean (BRepLib_FindSurface::*)() const) &BRepLib_FindSurface::Found, "None");
cls_BRepLib_FindSurface.def("Surface", (opencascade::handle<Geom_Surface> (BRepLib_FindSurface::*)() const) &BRepLib_FindSurface::Surface, "None");
cls_BRepLib_FindSurface.def("Tolerance", (Standard_Real (BRepLib_FindSurface::*)() const) &BRepLib_FindSurface::Tolerance, "None");
cls_BRepLib_FindSurface.def("ToleranceReached", (Standard_Real (BRepLib_FindSurface::*)() const) &BRepLib_FindSurface::ToleranceReached, "None");
cls_BRepLib_FindSurface.def("Existed", (Standard_Boolean (BRepLib_FindSurface::*)() const) &BRepLib_FindSurface::Existed, "None");
cls_BRepLib_FindSurface.def("Location", (TopLoc_Location (BRepLib_FindSurface::*)() const) &BRepLib_FindSurface::Location, "None");

// CLASS: BREPLIB_FUSEEDGES
py::class_<BRepLib_FuseEdges> cls_BRepLib_FuseEdges(mod, "BRepLib_FuseEdges", "This class can detect vertices in a face that can be considered useless and then perform the fuse of the edges and remove the useless vertices. By useles vertices, we mean : * vertices that have exactly two connex edges * the edges connex to the vertex must have exactly the same 2 connex faces . * The edges connex to the vertex must have the same geometric support.");

// Constructors
cls_BRepLib_FuseEdges.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
cls_BRepLib_FuseEdges.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("theShape"), py::arg("PerformNow"));

// Methods
// cls_BRepLib_FuseEdges.def_static("operator new_", (void * (*)(size_t)) &BRepLib_FuseEdges::operator new, "None", py::arg("theSize"));
// cls_BRepLib_FuseEdges.def_static("operator delete_", (void (*)(void *)) &BRepLib_FuseEdges::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_FuseEdges.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_FuseEdges::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_FuseEdges.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_FuseEdges::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_FuseEdges.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_FuseEdges::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_FuseEdges.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_FuseEdges::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_FuseEdges.def("AvoidEdges", (void (BRepLib_FuseEdges::*)(const TopTools_IndexedMapOfShape &)) &BRepLib_FuseEdges::AvoidEdges, "set edges to avoid being fused", py::arg("theMapEdg"));
cls_BRepLib_FuseEdges.def("SetConcatBSpl", [](BRepLib_FuseEdges &self) -> void { return self.SetConcatBSpl(); });
cls_BRepLib_FuseEdges.def("SetConcatBSpl", (void (BRepLib_FuseEdges::*)(const Standard_Boolean)) &BRepLib_FuseEdges::SetConcatBSpl, "set mode to enable concatenation G1 BSpline edges in one End Modified by IFV 19.04.07", py::arg("theConcatBSpl"));
cls_BRepLib_FuseEdges.def("Edges", (void (BRepLib_FuseEdges::*)(TopTools_DataMapOfIntegerListOfShape &)) &BRepLib_FuseEdges::Edges, "returns all the list of edges to be fused each list of the map represent a set of connex edges that can be fused.", py::arg("theMapLstEdg"));
cls_BRepLib_FuseEdges.def("ResultEdges", (void (BRepLib_FuseEdges::*)(TopTools_DataMapOfIntegerShape &)) &BRepLib_FuseEdges::ResultEdges, "returns all the fused edges. each integer entry in the map corresponds to the integer in the DataMapOfIntegerListOfShape we get in method Edges. That is to say, to the list of edges in theMapLstEdg(i) corresponds the resulting edge theMapEdge(i)", py::arg("theMapEdg"));
cls_BRepLib_FuseEdges.def("Faces", (void (BRepLib_FuseEdges::*)(TopTools_DataMapOfShapeShape &)) &BRepLib_FuseEdges::Faces, "returns the map of modified faces.", py::arg("theMapFac"));
cls_BRepLib_FuseEdges.def("Shape", (TopoDS_Shape & (BRepLib_FuseEdges::*)()) &BRepLib_FuseEdges::Shape, "returns myShape modified with the list of internal edges removed from it.");
cls_BRepLib_FuseEdges.def("NbVertices", (Standard_Integer (BRepLib_FuseEdges::*)()) &BRepLib_FuseEdges::NbVertices, "returns the number of vertices candidate to be removed");
cls_BRepLib_FuseEdges.def("Perform", (void (BRepLib_FuseEdges::*)()) &BRepLib_FuseEdges::Perform, "Using map of list of connex edges, fuse each list to one edge and then update myShape");


}
