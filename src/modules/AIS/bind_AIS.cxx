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
#include <gp_Pnt.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_Lin.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <TopoDS_Edge.hxx>
#include <Geom_Plane.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Pln.hxx>
#include <Geom_Surface.hxx>
#include <AIS_KindOfSurface.hxx>
#include <gp_Dir.hxx>
#include <Bnd_Box.hxx>
#include <gp_Elips.hxx>
#include <Prs3d_Presentation.hxx>
#include <Prs3d_Drawer.hxx>
#include <Quantity_NameOfColor.hxx>
#include <Aspect_TypeOfLine.hxx>
#include <Aspect_TypeOfMarker.hxx>
#include <AIS.hxx>

void bind_AIS(py::module &mod){

py::class_<AIS, std::unique_ptr<AIS>> cls_AIS(mod, "AIS", "Application Interactive Services provide the means to create links between an application GUI viewer and the packages which are used to manage selection and presentation. The tools AIS defined in order to do this include different sorts of entities: both the selectable viewable objects themselves and the context and attribute managers to define their selection and display. To orient the user as he works in a modeling environment, views and selections must be comprehensible. There must be several different sorts of selectable and viewable object defined. These must also be interactive, that is, connecting graphic representation and the underlying reference geometry. These entities are called Interactive Objects, and are divided into four types: - the Datum - the Relation - the Object - None. The Datum groups together the construction elements such as lines, circles, points, trihedra, plane trihedra, planes and axes. The Relation is made up of constraints on one or more interactive shapes and the corresponding reference geometry. For example, you might want to constrain two edges in a parallel relation. This contraint is considered as an object in its own right, and is shown as a sensitive primitive. This takes the graphic form of a perpendicular arrow marked with the || symbol and lying between the two edges. The Object type includes topological shapes, and connections between shapes. None, in order not to eliminate the object, tells the application to look further until it finds an object definition in its generation which is accepted. Inside these categories, you have the possibility of an additional characterization by means of a signature. The signature provides an index to the further characterization. By default, the Interactive Object has a None type and a signature of 0 (equivalent to None.) If you want to give a particular type and signature to your interactive object, you must redefine the two virtual methods: Type and Signature. In the C++ inheritance structure of the package, each class representing a specific Interactive Object inherits AIS_InteractiveObject. Among these inheriting classes, AIS_Relation functions as the abstract mother class for tinheriting classes defining display of specific relational constraints and types of dimension. Some of these include: - display of constraints based on relations of symmetry, tangency, parallelism and concentricity - display of dimensions for angles, offsets, diameters, radii and chamfers. No viewer can show everything at once with any coherence or clarity. Views must be managed carefully both sequentially and at any given instant. Another function of the view is that of a context to carry out design in. The design changes are applied to the objects in the view and then extended to the underlying reference geometry by a solver. To make sense of this complicated visual data, several display and selection tools are required. To facilitate management, each object and each construction element has a selection priority. There are also means to modify the default priority. To define an environment of dynamic detection, you can use standard filter classes or create your own. A filter questions the owner of the sensitive primitive to determine if it has the the desired qualities. If it answers positively, it is kept. If not, it is rejected. The standard filters supplied in AIS include: - AIS_AttributeFilter - AIS_SignatureFilter - AIS_TypeFilter. A set of functions allows you to choose the interactive objects which you want to act on, the selection modes which you want to activate. An interactive object can have a certain number of graphic attributes which are specific to it, such as visualization mode, color, and material. By the same token, the interactive context has a set of graphic attributes, the Drawer which is valid by default for the objects it controls. When an interactive object is visualized, the required graphic attributes are first taken from the object's own Drawer if one exists, or from the context drawer for the others.");

// Constructors

// Fields

// Methods
// cls_AIS.def_static("operator new_", (void * (*)(size_t)) &AIS::operator new, "None", py::arg("theSize"));
// cls_AIS.def_static("operator delete_", (void (*)(void *)) &AIS::operator delete, "None", py::arg("theAddress"));
// cls_AIS.def_static("operator new[]_", (void * (*)(size_t)) &AIS::operator new[], "None", py::arg("theSize"));
// cls_AIS.def_static("operator delete[]_", (void (*)(void *)) &AIS::operator delete[], "None", py::arg("theAddress"));
// cls_AIS.def_static("operator new_", (void * (*)(size_t, void *)) &AIS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AIS.def_static("operator delete_", (void (*)(void *, void *)) &AIS::operator delete, "None", py::arg(""), py::arg(""));
cls_AIS.def_static("Nearest_", (gp_Pnt (*)(const TopoDS_Shape &, const gp_Pnt &)) &AIS::Nearest, "Returns the nearest point in a shape. This is used by several classes in calculation of dimensions.", py::arg("aShape"), py::arg("aPoint"));
cls_AIS.def_static("Nearest_", (gp_Pnt (*)(const gp_Lin &, const gp_Pnt &)) &AIS::Nearest, "Returns the nearest point on the line.", py::arg("theLine"), py::arg("thePoint"));
cls_AIS.def_static("Nearest_", (Standard_Boolean (*)(const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, gp_Pnt &)) &AIS::Nearest, "For the given point finds nearest point on the curve,", py::arg("theCurve"), py::arg("thePoint"), py::arg("theFirstPoint"), py::arg("theLastPoint"), py::arg("theNearestPoint"));
cls_AIS.def_static("Farest_", (gp_Pnt (*)(const TopoDS_Shape &, const gp_Pnt &)) &AIS::Farest, "None", py::arg("aShape"), py::arg("aPoint"));
cls_AIS.def_static("ComputeGeometry_", (Standard_Boolean (*)(const TopoDS_Edge &, opencascade::handle<Geom_Curve> &, gp_Pnt &, gp_Pnt &)) &AIS::ComputeGeometry, "Used by 2d Relation only Computes the 3d geometry of <anEdge> in the current WorkingPlane and the extremities if any Return TRUE if ok.", py::arg("theEdge"), py::arg("theCurve"), py::arg("theFirstPnt"), py::arg("theLastPnt"));
cls_AIS.def_static("ComputeGeometry_", [](const TopoDS_Edge & theEdge, opencascade::handle<Geom_Curve> & theCurve, gp_Pnt & theFirstPnt, gp_Pnt & theLastPnt, Standard_Boolean & theIsInfinite){ Standard_Boolean rv = AIS::ComputeGeometry(theEdge, theCurve, theFirstPnt, theLastPnt, theIsInfinite); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, theIsInfinite); }, "Used by dimensions only. Computes the 3d geometry of <anEdge>. Return TRUE if ok.", py::arg("theEdge"), py::arg("theCurve"), py::arg("theFirstPnt"), py::arg("theLastPnt"), py::arg("theIsInfinite"));
cls_AIS.def_static("ComputeGeometry_", [](const TopoDS_Edge & theEdge, opencascade::handle<Geom_Curve> & theCurve, gp_Pnt & theFirstPnt, gp_Pnt & theLastPnt, opencascade::handle<Geom_Curve> & theExtCurve, Standard_Boolean & theIsInfinite, Standard_Boolean & theIsOnPlane, const opencascade::handle<Geom_Plane> & thePlane){ Standard_Boolean rv = AIS::ComputeGeometry(theEdge, theCurve, theFirstPnt, theLastPnt, theExtCurve, theIsInfinite, theIsOnPlane, thePlane); return std::tuple<Standard_Boolean, Standard_Boolean &, Standard_Boolean &>(rv, theIsInfinite, theIsOnPlane); }, "Used by 2d Relation only Computes the 3d geometry of <anEdge> in the current WorkingPlane and the extremities if any. If <aCurve> is not in the current plane, <extCurve> contains the not projected curve associated to <anEdge>. If <anEdge> is infinite, <isinfinite> = true and the 2 parameters <FirstPnt> and <LastPnt> have no signification. Return TRUE if ok.", py::arg("theEdge"), py::arg("theCurve"), py::arg("theFirstPnt"), py::arg("theLastPnt"), py::arg("theExtCurve"), py::arg("theIsInfinite"), py::arg("theIsOnPlane"), py::arg("thePlane"));
cls_AIS.def_static("ComputeGeometry_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Edge &, opencascade::handle<Geom_Curve> &, opencascade::handle<Geom_Curve> &, gp_Pnt &, gp_Pnt &, gp_Pnt &, gp_Pnt &, const opencascade::handle<Geom_Plane> &)) &AIS::ComputeGeometry, "Used by 2d Relation only Computes the 3d geometry of <anEdge> in the current WorkingPlane and the extremities if any Return TRUE if ok.", py::arg("theFirstEdge"), py::arg("theSecondEdge"), py::arg("theFirstCurve"), py::arg("theSecondCurve"), py::arg("theFirstPnt1"), py::arg("theLastPnt1"), py::arg("theFirstPnt2"), py::arg("theLastPnt2"), py::arg("thePlane"));
cls_AIS.def_static("ComputeGeometry_", [](const TopoDS_Edge & theFirstEdge, const TopoDS_Edge & theSecondEdge, opencascade::handle<Geom_Curve> & theFirstCurve, opencascade::handle<Geom_Curve> & theSecondCurve, gp_Pnt & theFirstPnt1, gp_Pnt & theLastPnt1, gp_Pnt & theFirstPnt2, gp_Pnt & theLastPnt2, Standard_Boolean & theIsinfinite1, Standard_Boolean & theIsinfinite2){ Standard_Boolean rv = AIS::ComputeGeometry(theFirstEdge, theSecondEdge, theFirstCurve, theSecondCurve, theFirstPnt1, theLastPnt1, theFirstPnt2, theLastPnt2, theIsinfinite1, theIsinfinite2); return std::tuple<Standard_Boolean, Standard_Boolean &, Standard_Boolean &>(rv, theIsinfinite1, theIsinfinite2); }, "Used by dimensions only.Computes the 3d geometry of<anEdge1> and <anEdge2> and checks if they are infinite.", py::arg("theFirstEdge"), py::arg("theSecondEdge"), py::arg("theFirstCurve"), py::arg("theSecondCurve"), py::arg("theFirstPnt1"), py::arg("theLastPnt1"), py::arg("theFirstPnt2"), py::arg("theLastPnt2"), py::arg("theIsinfinite1"), py::arg("theIsinfinite2"));
cls_AIS.def_static("ComputeGeometry_", [](const TopoDS_Edge & theFirstEdge, const TopoDS_Edge & theSecondEdge, Standard_Integer & theExtIndex, opencascade::handle<Geom_Curve> & theFirstCurve, opencascade::handle<Geom_Curve> & theSecondCurve, gp_Pnt & theFirstPnt1, gp_Pnt & theLastPnt1, gp_Pnt & theFirstPnt2, gp_Pnt & theLastPnt2, opencascade::handle<Geom_Curve> & theExtCurve, Standard_Boolean & theIsinfinite1, Standard_Boolean & theIsinfinite2, const opencascade::handle<Geom_Plane> & thePlane){ Standard_Boolean rv = AIS::ComputeGeometry(theFirstEdge, theSecondEdge, theExtIndex, theFirstCurve, theSecondCurve, theFirstPnt1, theLastPnt1, theFirstPnt2, theLastPnt2, theExtCurve, theIsinfinite1, theIsinfinite2, thePlane); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Boolean &, Standard_Boolean &>(rv, theExtIndex, theIsinfinite1, theIsinfinite2); }, "Used by 2d Relation only Computes the 3d geometry of<anEdge1> and <anEdge2> in the current Plane and the extremities if any. Return in ExtCurve the 3d curve (not projected in the plane) of the first edge if <indexExt> =1 or of the 2nd edge if <indexExt> = 2. If <indexExt> = 0, ExtCurve is Null. if there is an edge external to the plane, <isinfinite> is true if this edge is infinite. So, the extremities of it are not significant. Return TRUE if ok", py::arg("theFirstEdge"), py::arg("theSecondEdge"), py::arg("theExtIndex"), py::arg("theFirstCurve"), py::arg("theSecondCurve"), py::arg("theFirstPnt1"), py::arg("theLastPnt1"), py::arg("theFirstPnt2"), py::arg("theLastPnt2"), py::arg("theExtCurve"), py::arg("theIsinfinite1"), py::arg("theIsinfinite2"), py::arg("thePlane"));
cls_AIS.def_static("ComputeGeomCurve_", [](opencascade::handle<Geom_Curve> & aCurve, const Standard_Real first1, const Standard_Real last1, gp_Pnt & FirstPnt1, gp_Pnt & LastPnt1, const opencascade::handle<Geom_Plane> & aPlane, Standard_Boolean & isOnPlane){ Standard_Boolean rv = AIS::ComputeGeomCurve(aCurve, first1, last1, FirstPnt1, LastPnt1, aPlane, isOnPlane); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, isOnPlane); }, "Checks if aCurve belongs to aPlane; if not, projects aCurve in aPlane and returns aCurve; Return TRUE if ok", py::arg("aCurve"), py::arg("first1"), py::arg("last1"), py::arg("FirstPnt1"), py::arg("LastPnt1"), py::arg("aPlane"), py::arg("isOnPlane"));
cls_AIS.def_static("ComputeGeometry_", [](const TopoDS_Vertex & aVertex, gp_Pnt & point, const opencascade::handle<Geom_Plane> & aPlane, Standard_Boolean & isOnPlane){ Standard_Boolean rv = AIS::ComputeGeometry(aVertex, point, aPlane, isOnPlane); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, isOnPlane); }, "None", py::arg("aVertex"), py::arg("point"), py::arg("aPlane"), py::arg("isOnPlane"));
cls_AIS.def_static("GetPlaneFromFace_", [](const TopoDS_Face & aFace, gp_Pln & aPlane, opencascade::handle<Geom_Surface> & aSurf, AIS_KindOfSurface & aSurfType, Standard_Real & Offset){ Standard_Boolean rv = AIS::GetPlaneFromFace(aFace, aPlane, aSurf, aSurfType, Offset); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Offset); }, "Tryes to get Plane from Face. Returns Surface of Face in aSurf. Returns Standard_True and Plane of Face in aPlane in following cases: Face is Plane, Offset of Plane, Extrusion of Line and Offset of Extrusion of Line Returns pure type of Surface which can be: Plane, Cylinder, Cone, Sphere, Torus, SurfaceOfRevolution, SurfaceOfExtrusion", py::arg("aFace"), py::arg("aPlane"), py::arg("aSurf"), py::arg("aSurfType"), py::arg("Offset"));
cls_AIS.def_static("InitFaceLength_", [](const TopoDS_Face & aFace, gp_Pln & aPlane, opencascade::handle<Geom_Surface> & aSurface, AIS_KindOfSurface & aSurfaceType, Standard_Real & anOffset){ AIS::InitFaceLength(aFace, aPlane, aSurface, aSurfaceType, anOffset); return anOffset; }, "None", py::arg("aFace"), py::arg("aPlane"), py::arg("aSurface"), py::arg("aSurfaceType"), py::arg("anOffset"));
cls_AIS.def_static("InitLengthBetweenCurvilinearFaces_", (void (*)(const TopoDS_Face &, const TopoDS_Face &, opencascade::handle<Geom_Surface> &, opencascade::handle<Geom_Surface> &, gp_Pnt &, gp_Pnt &, gp_Dir &)) &AIS::InitLengthBetweenCurvilinearFaces, "Finds attachment points on two curvilinear faces for length dimension.", py::arg("theFirstFace"), py::arg("theSecondFace"), py::arg("theFirstSurf"), py::arg("theSecondSurf"), py::arg("theFirstAttach"), py::arg("theSecondAttach"), py::arg("theDirOnPlane"));
cls_AIS.def_static("InitAngleBetweenPlanarFaces_", [](const TopoDS_Face & a0, const TopoDS_Face & a1, gp_Pnt & a2, gp_Pnt & a3, gp_Pnt & a4) -> Standard_Boolean { return AIS::InitAngleBetweenPlanarFaces(a0, a1, a2, a3, a4); });
cls_AIS.def_static("InitAngleBetweenPlanarFaces_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Face &, gp_Pnt &, gp_Pnt &, gp_Pnt &, const Standard_Boolean)) &AIS::InitAngleBetweenPlanarFaces, "Finds three points for the angle dimension between two planes.", py::arg("theFirstFace"), py::arg("theSecondFace"), py::arg("theCenter"), py::arg("theFirstAttach"), py::arg("theSecondAttach"), py::arg("theIsFirstPointSet"));
cls_AIS.def_static("InitAngleBetweenCurvilinearFaces_", [](const TopoDS_Face & a0, const TopoDS_Face & a1, const AIS_KindOfSurface a2, const AIS_KindOfSurface a3, gp_Pnt & a4, gp_Pnt & a5, gp_Pnt & a6) -> Standard_Boolean { return AIS::InitAngleBetweenCurvilinearFaces(a0, a1, a2, a3, a4, a5, a6); });
cls_AIS.def_static("InitAngleBetweenCurvilinearFaces_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Face &, const AIS_KindOfSurface, const AIS_KindOfSurface, gp_Pnt &, gp_Pnt &, gp_Pnt &, const Standard_Boolean)) &AIS::InitAngleBetweenCurvilinearFaces, "Finds three points for the angle dimension between two curvilinear surfaces.", py::arg("theFirstFace"), py::arg("theSecondFace"), py::arg("theFirstSurfType"), py::arg("theSecondSurfType"), py::arg("theCenter"), py::arg("theFirstAttach"), py::arg("theSecondAttach"), py::arg("theIsFirstPointSet"));
cls_AIS.def_static("ProjectPointOnPlane_", (gp_Pnt (*)(const gp_Pnt &, const gp_Pln &)) &AIS::ProjectPointOnPlane, "None", py::arg("aPoint"), py::arg("aPlane"));
cls_AIS.def_static("ProjectPointOnLine_", (gp_Pnt (*)(const gp_Pnt &, const gp_Lin &)) &AIS::ProjectPointOnLine, "None", py::arg("aPoint"), py::arg("aLine"));
cls_AIS.def_static("TranslatePointToBound_", (gp_Pnt (*)(const gp_Pnt &, const gp_Dir &, const Bnd_Box &)) &AIS::TranslatePointToBound, "None", py::arg("aPoint"), py::arg("aDir"), py::arg("aBndBox"));
cls_AIS.def_static("InDomain_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real)) &AIS::InDomain, "returns True if point with anAttachPar is in domain of arc", py::arg("aFirstPar"), py::arg("aLastPar"), py::arg("anAttachPar"));
cls_AIS.def_static("NearestApex_", [](const gp_Elips & elips, const gp_Pnt & pApex, const gp_Pnt & nApex, const Standard_Real fpara, const Standard_Real lpara, Standard_Boolean & IsInDomain){ gp_Pnt rv = AIS::NearestApex(elips, pApex, nApex, fpara, lpara, IsInDomain); return std::tuple<gp_Pnt, Standard_Boolean &>(rv, IsInDomain); }, "computes nearest to ellipse arc apex", py::arg("elips"), py::arg("pApex"), py::arg("nApex"), py::arg("fpara"), py::arg("lpara"), py::arg("IsInDomain"));
cls_AIS.def_static("DistanceFromApex_", (Standard_Real (*)(const gp_Elips &, const gp_Pnt &, const Standard_Real)) &AIS::DistanceFromApex, "computes length of ellipse arc in parametric units", py::arg("elips"), py::arg("Apex"), py::arg("par"));
cls_AIS.def_static("ComputeProjEdgePresentation_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TopoDS_Edge & a2, const opencascade::handle<Geom_Curve> & a3, const gp_Pnt & a4, const gp_Pnt & a5) -> void { return AIS::ComputeProjEdgePresentation(a0, a1, a2, a3, a4, a5); });
cls_AIS.def_static("ComputeProjEdgePresentation_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TopoDS_Edge & a2, const opencascade::handle<Geom_Curve> & a3, const gp_Pnt & a4, const gp_Pnt & a5, const Quantity_NameOfColor a6) -> void { return AIS::ComputeProjEdgePresentation(a0, a1, a2, a3, a4, a5, a6); });
cls_AIS.def_static("ComputeProjEdgePresentation_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TopoDS_Edge & a2, const opencascade::handle<Geom_Curve> & a3, const gp_Pnt & a4, const gp_Pnt & a5, const Quantity_NameOfColor a6, const Standard_Real a7) -> void { return AIS::ComputeProjEdgePresentation(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_AIS.def_static("ComputeProjEdgePresentation_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TopoDS_Edge & a2, const opencascade::handle<Geom_Curve> & a3, const gp_Pnt & a4, const gp_Pnt & a5, const Quantity_NameOfColor a6, const Standard_Real a7, const Aspect_TypeOfLine a8) -> void { return AIS::ComputeProjEdgePresentation(a0, a1, a2, a3, a4, a5, a6, a7, a8); });
cls_AIS.def_static("ComputeProjEdgePresentation_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TopoDS_Edge &, const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &, const Quantity_NameOfColor, const Standard_Real, const Aspect_TypeOfLine, const Aspect_TypeOfLine)) &AIS::ComputeProjEdgePresentation, "None", py::arg("aPres"), py::arg("aDrawer"), py::arg("anEdge"), py::arg("ProjCurve"), py::arg("FirstP"), py::arg("LastP"), py::arg("aColor"), py::arg("aWidth"), py::arg("aProjTOL"), py::arg("aCallTOL"));
cls_AIS.def_static("ComputeProjVertexPresentation_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TopoDS_Vertex & a2, const gp_Pnt & a3) -> void { return AIS::ComputeProjVertexPresentation(a0, a1, a2, a3); });
cls_AIS.def_static("ComputeProjVertexPresentation_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TopoDS_Vertex & a2, const gp_Pnt & a3, const Quantity_NameOfColor a4) -> void { return AIS::ComputeProjVertexPresentation(a0, a1, a2, a3, a4); });
cls_AIS.def_static("ComputeProjVertexPresentation_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TopoDS_Vertex & a2, const gp_Pnt & a3, const Quantity_NameOfColor a4, const Standard_Real a5) -> void { return AIS::ComputeProjVertexPresentation(a0, a1, a2, a3, a4, a5); });
cls_AIS.def_static("ComputeProjVertexPresentation_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TopoDS_Vertex & a2, const gp_Pnt & a3, const Quantity_NameOfColor a4, const Standard_Real a5, const Aspect_TypeOfMarker a6) -> void { return AIS::ComputeProjVertexPresentation(a0, a1, a2, a3, a4, a5, a6); });
cls_AIS.def_static("ComputeProjVertexPresentation_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TopoDS_Vertex &, const gp_Pnt &, const Quantity_NameOfColor, const Standard_Real, const Aspect_TypeOfMarker, const Aspect_TypeOfLine)) &AIS::ComputeProjVertexPresentation, "None", py::arg("aPres"), py::arg("aDrawer"), py::arg("aVertex"), py::arg("ProjPoint"), py::arg("aColor"), py::arg("aWidth"), py::arg("aProjTOM"), py::arg("aCallTOL"));

// Enums

}