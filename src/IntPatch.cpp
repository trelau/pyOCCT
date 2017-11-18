#include <pyOCCT_Common.hpp>

#include <IntPatch_Polyhedron.hxx>

#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HVertex.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <IntSurf_Transition.hxx>
#include <IntPatch_Point.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <IntPatch_SequenceOfPoint.hxx>
#include <IntPatch_IType.hxx>
#include <Standard_Transient.hxx>
#include <IntSurf_TypeTrans.hxx>
#include <IntSurf_Situation.hxx>
#include <Standard_Type.hxx>
#include <IntPatch_Line.hxx>
#include <IntPatch_SequenceOfLine.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <IntSurf_ListOfPntOn2S.hxx>
#include <IntPatch_Intersection.hxx>
#include <IntAna_Curve.hxx>
#include <gp_Vec.hxx>
#include <IntPatch_ALine.hxx>
#include <IntPatch_PointLine.hxx>
#include <IntSurf_LineOn2S.hxx>
#include <IntPatch_RLine.hxx>
#include <gp_Pnt2d.hxx>
#include <IntPatch_WLine.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Parab.hxx>
#include <gp_Hypr.hxx>
#include <IntPatch_GLine.hxx>
#include <IntPatch_ALineToWLine.hxx>
#include <math_FunctionWithDerivative.hxx>
#include <IntSurf_Quadric.hxx>
#include <IntPatch_ArcFunction.hxx>
#include <math_FunctionSetWithDerivatives.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <IntPatch_CSFunction.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_Vec2d.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Parab2d.hxx>
#include <Geom2d_BezierCurve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <IntPatch_HCurve2dTool.hxx>
#include <math_FunctionSetRoot.hxx>
#include <IntPatch_CurvIntSurf.hxx>
#include <IntPatch_HInterTool.hxx>
#include <IntPatch_ThePathPointOfTheSOnBounds.hxx>
#include <IntPatch_TheSegmentOfTheSOnBounds.hxx>
#include <IntPatch_SequenceOfSegmentOfTheSOnBounds.hxx>
#include <IntPatch_SequenceOfPathPointOfTheSOnBounds.hxx>
#include <IntPatch_TheSOnBounds.hxx>
#include <IntPatch_ImpImpIntersection.hxx>
#include <gp_Dir2d.hxx>
#include <IntPatch_TheSurfFunction.hxx>
#include <IntSurf_InteriorPoint.hxx>
#include <IntPatch_TheSearchInside.hxx>
#include <IntPatch_ImpPrmIntersection.hxx>
#include <Bnd_Box.hxx>
#include <Bnd_HArray1OfBox.hxx>
#include <gp_XYZ.hxx>
#include <IntPatch_Polyhedron.hxx>
#include <Intf_Interference.hxx>
#include <IntPatch_InterferencePolyhedron.hxx>
#include <IntPatch_LineConstructor.hxx>
#include <Intf_Polygon2d.hxx>
#include <IntPatch_Polygo.hxx>
#include <Bnd_Box2d.hxx>
#include <IntPatch_PolyArc.hxx>
#include <IntPatch_PolyhedronTool.hxx>
#include <IntPatch_PolyLine.hxx>
#include <IntPatch_PrmPrmIntersection_T3Bits.hxx>
#include <IntPatch_PrmPrmIntersection.hxx>
#include <IntPatch_RstInt.hxx>
#include <IntPatch_SearchPnt.hxx>
#include <IntSurf_Allocator.hxx>
#include <IntSurf_PathPoint.hxx>
#include <IntPatch_TheIWLineOfTheIWalking.hxx>
#include <IntPatch_SequenceOfIWLineOfTheIWalking.hxx>
#include <IntPatch_SpecPntType.hxx>
#include <IntPatch_SpecialPoints.hxx>
#include <IntSurf_SequenceOfPathPoint.hxx>
#include <IntSurf_SequenceOfInteriorPoint.hxx>
#include <IntPatch_TheIWalking.hxx>
#include <IntPatch_WLineTool.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(IntPatch, mod) {

	// IMPORT
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.IntSurf");
	py::module::import("OCCT.Adaptor3d");
	py::module::import("OCCT.Adaptor2d");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.IntAna");
	py::module::import("OCCT.math");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.Bnd");
	py::module::import("OCCT.Intf");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_IType.hxx
	py::enum_<IntPatch_IType>(mod, "IntPatch_IType", "None")
		.value("IntPatch_Lin", IntPatch_IType::IntPatch_Lin)
		.value("IntPatch_Circle", IntPatch_IType::IntPatch_Circle)
		.value("IntPatch_Ellipse", IntPatch_IType::IntPatch_Ellipse)
		.value("IntPatch_Parabola", IntPatch_IType::IntPatch_Parabola)
		.value("IntPatch_Hyperbola", IntPatch_IType::IntPatch_Hyperbola)
		.value("IntPatch_Analytic", IntPatch_IType::IntPatch_Analytic)
		.value("IntPatch_Walking", IntPatch_IType::IntPatch_Walking)
		.value("IntPatch_Restriction", IntPatch_IType::IntPatch_Restriction)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_SpecPntType.hxx
	py::enum_<IntPatch_SpecPntType>(mod, "IntPatch_SpecPntType", "This enum describe the different kinds of special (singular) points of Surface-Surface intersection algorithm. Such as pole of sphere, apex of cone, point on U- or V-seam etc.")
		.value("IntPatch_SPntNone", IntPatch_SpecPntType::IntPatch_SPntNone)
		.value("IntPatch_SPntSeamU", IntPatch_SpecPntType::IntPatch_SPntSeamU)
		.value("IntPatch_SPntSeamV", IntPatch_SpecPntType::IntPatch_SPntSeamV)
		.value("IntPatch_SPntSeamUV", IntPatch_SpecPntType::IntPatch_SPntSeamUV)
		.value("IntPatch_SPntPoleSeamU", IntPatch_SpecPntType::IntPatch_SPntPoleSeamU)
		.value("IntPatch_SPntPole", IntPatch_SpecPntType::IntPatch_SPntPole)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_Point.hxx
	py::class_<IntPatch_Point, std::unique_ptr<IntPatch_Point, Deleter<IntPatch_Point>>> cls_IntPatch_Point(mod, "IntPatch_Point", "Definition of an intersection point between two surfaces. Such a point is contains geometrical informations (see the Value method) and logical informations.");
	cls_IntPatch_Point.def(py::init<>());
	cls_IntPatch_Point.def("SetValue", (void (IntPatch_Point::*)(const gp_Pnt &, const Standard_Real, const Standard_Boolean)) &IntPatch_Point::SetValue, "Sets the values of a point which is on no domain, when both surfaces are implicit ones. If Tangent is True, the point is a point of tangency between the surfaces.", py::arg("Pt"), py::arg("Tol"), py::arg("Tangent"));
	cls_IntPatch_Point.def("SetValue", (void (IntPatch_Point::*)(const gp_Pnt &)) &IntPatch_Point::SetValue, "None", py::arg("Pt"));
	cls_IntPatch_Point.def("SetValue", (void (IntPatch_Point::*)(const IntSurf_PntOn2S &)) &IntPatch_Point::SetValue, "Sets the value of <pt> member", py::arg("thePOn2S"));
	cls_IntPatch_Point.def("SetTolerance", (void (IntPatch_Point::*)(const Standard_Real)) &IntPatch_Point::SetTolerance, "None", py::arg("Tol"));
	cls_IntPatch_Point.def("SetParameters", (void (IntPatch_Point::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_Point::SetParameters, "Sets the values of the parameters of the point on each surface.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
	cls_IntPatch_Point.def("SetParameter", (void (IntPatch_Point::*)(const Standard_Real)) &IntPatch_Point::SetParameter, "Set the value of the parameter on the intersection line.", py::arg("Para"));
	cls_IntPatch_Point.def("SetVertex", (void (IntPatch_Point::*)(const Standard_Boolean, const opencascade::handle<Adaptor3d_HVertex> &)) &IntPatch_Point::SetVertex, "Sets the values of a point which is a vertex on the initial facet of restriction of one of the surface. If OnFirst is True, the point is on the domain of the first patch, otherwise the point is on the domain of the second surface.", py::arg("OnFirst"), py::arg("V"));
	cls_IntPatch_Point.def("SetArc", (void (IntPatch_Point::*)(const Standard_Boolean, const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const IntSurf_Transition &, const IntSurf_Transition &)) &IntPatch_Point::SetArc, "Sets the values of a point which is on one of the domain, when both surfaces are implicit ones. If OnFirst is True, the point is on the domain of the first patch, otherwise the point is on the domain of the second surface.", py::arg("OnFirst"), py::arg("A"), py::arg("Param"), py::arg("TLine"), py::arg("TArc"));
	cls_IntPatch_Point.def("SetMultiple", (void (IntPatch_Point::*)(const Standard_Boolean)) &IntPatch_Point::SetMultiple, "Sets (or unsets) the point as a point on several intersection line.", py::arg("IsMult"));
	cls_IntPatch_Point.def("Value", (const gp_Pnt & (IntPatch_Point::*)() const ) &IntPatch_Point::Value, "Returns the intersection point (geometric information).");
	cls_IntPatch_Point.def("ParameterOnLine", (Standard_Real (IntPatch_Point::*)() const ) &IntPatch_Point::ParameterOnLine, "This method returns the parameter of the point on the intersection line. If the points does not belong to an intersection line, the value returned does not have any sens.");
	cls_IntPatch_Point.def("Tolerance", (Standard_Real (IntPatch_Point::*)() const ) &IntPatch_Point::Tolerance, "This method returns the fuzziness on the point.");
	cls_IntPatch_Point.def("IsTangencyPoint", (Standard_Boolean (IntPatch_Point::*)() const ) &IntPatch_Point::IsTangencyPoint, "Returns True if the Point is a tangency point between the surfaces. If the Point is on one of the domain (IsOnDomS1 returns True or IsOnDomS2 returns True), an exception is raised.");
	cls_IntPatch_Point.def("ParametersOnS1", (void (IntPatch_Point::*)(Standard_Real &, Standard_Real &) const ) &IntPatch_Point::ParametersOnS1, "Returns the parameters on the first surface of the point.", py::arg("U1"), py::arg("V1"));
	cls_IntPatch_Point.def("ParametersOnS2", (void (IntPatch_Point::*)(Standard_Real &, Standard_Real &) const ) &IntPatch_Point::ParametersOnS2, "Returns the parameters on the second surface of the point.", py::arg("U2"), py::arg("V2"));
	cls_IntPatch_Point.def("IsMultiple", (Standard_Boolean (IntPatch_Point::*)() const ) &IntPatch_Point::IsMultiple, "Returns True if the point belongs to several intersection lines.");
	cls_IntPatch_Point.def("IsOnDomS1", (Standard_Boolean (IntPatch_Point::*)() const ) &IntPatch_Point::IsOnDomS1, "Returns TRUE if the point is on a boundary of the domain of the first patch.");
	cls_IntPatch_Point.def("IsVertexOnS1", (Standard_Boolean (IntPatch_Point::*)() const ) &IntPatch_Point::IsVertexOnS1, "Returns TRUE if the point is a vertex on the initial restriction facet of the first surface.");
	cls_IntPatch_Point.def("VertexOnS1", (const opencascade::handle<Adaptor3d_HVertex> & (IntPatch_Point::*)() const ) &IntPatch_Point::VertexOnS1, "Returns the information about the point when it is on the domain of the first patch, i-e when the function IsVertexOnS1 returns True. Otherwise, an exception is raised.");
	cls_IntPatch_Point.def("ArcOnS1", (const opencascade::handle<Adaptor2d_HCurve2d> & (IntPatch_Point::*)() const ) &IntPatch_Point::ArcOnS1, "Returns the arc of restriction containing the vertex. The exception DomainError is raised if IsOnDomS1 returns False.");
	cls_IntPatch_Point.def("TransitionLineArc1", (const IntSurf_Transition & (IntPatch_Point::*)() const ) &IntPatch_Point::TransitionLineArc1, "Returns the transition of the point on the intersection line with the arc on S1. The exception DomainError is raised if IsOnDomS1 returns False.");
	cls_IntPatch_Point.def("TransitionOnS1", (const IntSurf_Transition & (IntPatch_Point::*)() const ) &IntPatch_Point::TransitionOnS1, "Returns the transition between the intersection line returned by the method Line and the arc on S1 returned by ArcOnS1(). The exception DomainError is raised if IsOnDomS1 returns False.");
	cls_IntPatch_Point.def("ParameterOnArc1", (Standard_Real (IntPatch_Point::*)() const ) &IntPatch_Point::ParameterOnArc1, "Returns the parameter of the point on the arc returned by the method ArcOnS2. The exception DomainError is raised if IsOnDomS1 returns False.");
	cls_IntPatch_Point.def("IsOnDomS2", (Standard_Boolean (IntPatch_Point::*)() const ) &IntPatch_Point::IsOnDomS2, "Returns TRUE if the point is on a boundary of the domain of the second patch.");
	cls_IntPatch_Point.def("IsVertexOnS2", (Standard_Boolean (IntPatch_Point::*)() const ) &IntPatch_Point::IsVertexOnS2, "Returns TRUE if the point is a vertex on the initial restriction facet of the first surface.");
	cls_IntPatch_Point.def("VertexOnS2", (const opencascade::handle<Adaptor3d_HVertex> & (IntPatch_Point::*)() const ) &IntPatch_Point::VertexOnS2, "Returns the information about the point when it is on the domain of the second patch, i-e when the function IsVertexOnS2 returns True. Otherwise, an exception is raised.");
	cls_IntPatch_Point.def("ArcOnS2", (const opencascade::handle<Adaptor2d_HCurve2d> & (IntPatch_Point::*)() const ) &IntPatch_Point::ArcOnS2, "Returns the arc of restriction containing the vertex. The exception DomainError is raised if IsOnDomS2 returns False.");
	cls_IntPatch_Point.def("TransitionLineArc2", (const IntSurf_Transition & (IntPatch_Point::*)() const ) &IntPatch_Point::TransitionLineArc2, "Returns the transition of the point on the intersection line with the arc on S2. The exception DomainError is raised if IsOnDomS2 returns False.");
	cls_IntPatch_Point.def("TransitionOnS2", (const IntSurf_Transition & (IntPatch_Point::*)() const ) &IntPatch_Point::TransitionOnS2, "Returns the transition between the intersection line returned by the method Line and the arc on S2 returned by ArcOnS2. The exception DomainError is raised if IsOnDomS2 returns False.");
	cls_IntPatch_Point.def("ParameterOnArc2", (Standard_Real (IntPatch_Point::*)() const ) &IntPatch_Point::ParameterOnArc2, "Returns the parameter of the point on the arc returned by the method ArcOnS2. The exception DomainError is raised if IsOnDomS2 returns False.");
	cls_IntPatch_Point.def("PntOn2S", (const IntSurf_PntOn2S & (IntPatch_Point::*)() const ) &IntPatch_Point::PntOn2S, "Returns the PntOn2S (geometric Point and the parameters)");
	cls_IntPatch_Point.def("Parameters", (void (IntPatch_Point::*)(Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &) const ) &IntPatch_Point::Parameters, "Returns the parameters on the first and on the second surface of the point.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
	cls_IntPatch_Point.def("ReverseTransition", (void (IntPatch_Point::*)()) &IntPatch_Point::ReverseTransition, "None");
	// FIXME cls_IntPatch_Point.def("Dump", (void (IntPatch_Point::*)() const ) &IntPatch_Point::Dump, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_Line.hxx
	py::class_<IntPatch_Line, opencascade::handle<IntPatch_Line>, Standard_Transient> cls_IntPatch_Line(mod, "IntPatch_Line", "Definition of an intersection line between two surfaces. A line may be either geometric : line, circle, ellipse, parabola, hyperbola, as defined in the class GLine, or analytic, as defined in the class ALine, or defined by a set of points (coming from a walking algorithm) as defined in the class WLine.");
	cls_IntPatch_Line.def("SetValue", (void (IntPatch_Line::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &IntPatch_Line::SetValue, "To set the values returned by IsUIsoS1,.... The default values are False.", py::arg("Uiso1"), py::arg("Viso1"), py::arg("Uiso2"), py::arg("Viso2"));
	cls_IntPatch_Line.def("ArcType", (IntPatch_IType (IntPatch_Line::*)() const ) &IntPatch_Line::ArcType, "Returns the type of geometry 3d (Line, Circle, Parabola, Hyperbola, Ellipse, Analytic, Walking, Restriction)");
	cls_IntPatch_Line.def("IsTangent", (Standard_Boolean (IntPatch_Line::*)() const ) &IntPatch_Line::IsTangent, "Returns TRUE if the intersection is a line of tangency between the 2 patches.");
	cls_IntPatch_Line.def("TransitionOnS1", (IntSurf_TypeTrans (IntPatch_Line::*)() const ) &IntPatch_Line::TransitionOnS1, "Returns the type of the transition of the line for the first surface. The transition is 'constant' along the line. The transition is IN if the line is oriented in such a way that the system of vector (N1,N2,T) is right-handed, where N1 is the normal to the first surface at a point P, N2 is the normal to the second surface at a point P, T is the tangent to the intersection line at P. If the system of vector is left-handed, the transition is OUT. When N1 and N2 are colinear all along the intersection line, the transition will be - TOUCH, if it is possible to use the 2nd derivatives to determine the position of one surafce compared to the other (see Situation) - UNDECIDED otherwise.");
	cls_IntPatch_Line.def("TransitionOnS2", (IntSurf_TypeTrans (IntPatch_Line::*)() const ) &IntPatch_Line::TransitionOnS2, "Returns the type of the transition of the line for the second surface. The transition is 'constant' along the line.");
	cls_IntPatch_Line.def("SituationS1", (IntSurf_Situation (IntPatch_Line::*)() const ) &IntPatch_Line::SituationS1, "Returns the situation (INSIDE/OUTSIDE/UNKNOWN) of the first patch compared to the second one, when TransitionOnS1 or TransitionOnS2 returns TOUCH. Otherwise, an exception is raised.");
	cls_IntPatch_Line.def("SituationS2", (IntSurf_Situation (IntPatch_Line::*)() const ) &IntPatch_Line::SituationS2, "Returns the situation (INSIDE/OUTSIDE/UNKNOWN) of the second patch compared to the first one, when TransitionOnS1 or TransitionOnS2 returns TOUCH. Otherwise, an exception is raised.");
	cls_IntPatch_Line.def("IsUIsoOnS1", (Standard_Boolean (IntPatch_Line::*)() const ) &IntPatch_Line::IsUIsoOnS1, "Returns TRUE if the intersection is a U isoparametric curve on the first patch.");
	cls_IntPatch_Line.def("IsVIsoOnS1", (Standard_Boolean (IntPatch_Line::*)() const ) &IntPatch_Line::IsVIsoOnS1, "Returns TRUE if the intersection is a V isoparametric curve on the first patch.");
	cls_IntPatch_Line.def("IsUIsoOnS2", (Standard_Boolean (IntPatch_Line::*)() const ) &IntPatch_Line::IsUIsoOnS2, "Returns TRUE if the intersection is a U isoparametric curve on the second patch.");
	cls_IntPatch_Line.def("IsVIsoOnS2", (Standard_Boolean (IntPatch_Line::*)() const ) &IntPatch_Line::IsVIsoOnS2, "Returns TRUE if the intersection is a V isoparametric curve on the second patch.");
	cls_IntPatch_Line.def_static("get_type_name_", (const char * (*)()) &IntPatch_Line::get_type_name, "None");
	cls_IntPatch_Line.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntPatch_Line::get_type_descriptor, "None");
	cls_IntPatch_Line.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntPatch_Line::*)() const ) &IntPatch_Line::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_Intersection.hxx
	py::class_<IntPatch_Intersection, std::unique_ptr<IntPatch_Intersection, Deleter<IntPatch_Intersection>>> cls_IntPatch_Intersection(mod, "IntPatch_Intersection", "This class provides a generic algorithm to intersect 2 surfaces.");
	cls_IntPatch_Intersection.def(py::init<>());
	cls_IntPatch_Intersection.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real>(), py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"));
	cls_IntPatch_Intersection.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real>(), py::arg("S1"), py::arg("D1"), py::arg("TolArc"), py::arg("TolTang"));
	cls_IntPatch_Intersection.def("SetTolerances", (void (IntPatch_Intersection::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_Intersection::SetTolerances, "Set the tolerances used by the algorithms: --- Implicit - Parametric --- Parametric - Parametric --- Implicit - Implicit", py::arg("TolArc"), py::arg("TolTang"), py::arg("UVMaxStep"), py::arg("Fleche"));
	cls_IntPatch_Intersection.def("Perform", [](IntPatch_Intersection &self, const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_TopolTool> & a1, const opencascade::handle<Adaptor3d_HSurface> & a2, const opencascade::handle<Adaptor3d_TopolTool> & a3, const Standard_Real a4, const Standard_Real a5) -> void { return self.Perform(a0, a1, a2, a3, a4, a5); }, py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"));
	cls_IntPatch_Intersection.def("Perform", [](IntPatch_Intersection &self, const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_TopolTool> & a1, const opencascade::handle<Adaptor3d_HSurface> & a2, const opencascade::handle<Adaptor3d_TopolTool> & a3, const Standard_Real a4, const Standard_Real a5, const Standard_Boolean a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); }, py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"), py::arg("isGeomInt"));
	cls_IntPatch_Intersection.def("Perform", [](IntPatch_Intersection &self, const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_TopolTool> & a1, const opencascade::handle<Adaptor3d_HSurface> & a2, const opencascade::handle<Adaptor3d_TopolTool> & a3, const Standard_Real a4, const Standard_Real a5, const Standard_Boolean a6, const Standard_Boolean a7) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7); }, py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"), py::arg("isGeomInt"), py::arg("theIsReqToKeepRLine"));
	cls_IntPatch_Intersection.def("Perform", (void (IntPatch_Intersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &IntPatch_Intersection::Perform, "Flag theIsReqToKeepRLine has been enterred only for compatibility with TopOpeBRep package. It shall be deleted after deleting TopOpeBRep. When intersection result returns IntPatch_RLine and another IntPatch_Line (not restriction) we (in case of theIsReqToKeepRLine==TRUE) will always keep both lines even if they are coincided. Flag theIsReqToPostWLProc has been enterred only for compatibility with TopOpeBRep package. It shall be deleted after deleting TopOpeBRep. If theIsReqToPostWLProc == FALSE, then we will work with Walking-line obtained after intersection algorithm directly (wothout any post-processing).", py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"), py::arg("isGeomInt"), py::arg("theIsReqToKeepRLine"), py::arg("theIsReqToPostWLProc"));
	cls_IntPatch_Intersection.def("Perform", [](IntPatch_Intersection &self, const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_TopolTool> & a1, const opencascade::handle<Adaptor3d_HSurface> & a2, const opencascade::handle<Adaptor3d_TopolTool> & a3, const Standard_Real a4, const Standard_Real a5, IntSurf_ListOfPntOn2S & a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); }, py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"), py::arg("LOfPnts"));
	cls_IntPatch_Intersection.def("Perform", [](IntPatch_Intersection &self, const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_TopolTool> & a1, const opencascade::handle<Adaptor3d_HSurface> & a2, const opencascade::handle<Adaptor3d_TopolTool> & a3, const Standard_Real a4, const Standard_Real a5, IntSurf_ListOfPntOn2S & a6, const Standard_Boolean a7) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7); }, py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"), py::arg("LOfPnts"), py::arg("RestrictLine"));
	cls_IntPatch_Intersection.def("Perform", [](IntPatch_Intersection &self, const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_TopolTool> & a1, const opencascade::handle<Adaptor3d_HSurface> & a2, const opencascade::handle<Adaptor3d_TopolTool> & a3, const Standard_Real a4, const Standard_Real a5, IntSurf_ListOfPntOn2S & a6, const Standard_Boolean a7, const Standard_Boolean a8) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7, a8); }, py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"), py::arg("LOfPnts"), py::arg("RestrictLine"), py::arg("isGeomInt"));
	cls_IntPatch_Intersection.def("Perform", [](IntPatch_Intersection &self, const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_TopolTool> & a1, const opencascade::handle<Adaptor3d_HSurface> & a2, const opencascade::handle<Adaptor3d_TopolTool> & a3, const Standard_Real a4, const Standard_Real a5, IntSurf_ListOfPntOn2S & a6, const Standard_Boolean a7, const Standard_Boolean a8, const Standard_Boolean a9) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9); }, py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"), py::arg("LOfPnts"), py::arg("RestrictLine"), py::arg("isGeomInt"), py::arg("theIsReqToKeepRLine"));
	cls_IntPatch_Intersection.def("Perform", (void (IntPatch_Intersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, IntSurf_ListOfPntOn2S &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &IntPatch_Intersection::Perform, "If isGeomInt == Standard_False, then method Param-Param intersection will be used. Flag theIsReqToKeepRLine has been enterred only for compatibility with TopOpeBRep package. It shall be deleted after deleting TopOpeBRep. When intersection result returns IntPatch_RLine and another IntPatch_Line (not restriction) we (in case of theIsReqToKeepRLine==TRUE) will always keep both lines even if they are coincided. Flag theIsReqToPostWLProc has been enterred only for compatibility with TopOpeBRep package. It shall be deleted after deleting TopOpeBRep. If theIsReqToPostWLProc == FALSE, then we will work with Walking-line obtained after intersection algorithm directly (wothout any post-processing).", py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"), py::arg("LOfPnts"), py::arg("RestrictLine"), py::arg("isGeomInt"), py::arg("theIsReqToKeepRLine"), py::arg("theIsReqToPostWLProc"));
	cls_IntPatch_Intersection.def("Perform", (void (IntPatch_Intersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_Intersection::Perform, "Perform with start point", py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("TolArc"), py::arg("TolTang"));
	cls_IntPatch_Intersection.def("Perform", (void (IntPatch_Intersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real)) &IntPatch_Intersection::Perform, "Uses for finding self-intersected surfaces.", py::arg("S1"), py::arg("D1"), py::arg("TolArc"), py::arg("TolTang"));
	cls_IntPatch_Intersection.def("IsDone", (Standard_Boolean (IntPatch_Intersection::*)() const ) &IntPatch_Intersection::IsDone, "Returns True if the calculus was succesfull.");
	cls_IntPatch_Intersection.def("IsEmpty", (Standard_Boolean (IntPatch_Intersection::*)() const ) &IntPatch_Intersection::IsEmpty, "Returns true if the is no intersection.");
	cls_IntPatch_Intersection.def("TangentFaces", (Standard_Boolean (IntPatch_Intersection::*)() const ) &IntPatch_Intersection::TangentFaces, "Returns True if the two patches are considered as entierly tangent, i-e every restriction arc of one patch is inside the geometric base of the other patch.");
	cls_IntPatch_Intersection.def("OppositeFaces", (Standard_Boolean (IntPatch_Intersection::*)() const ) &IntPatch_Intersection::OppositeFaces, "Returns True when the TangentFaces returns True and the normal vectors evaluated at a point on the first and the second surface are opposite. The exception DomainError is raised if TangentFaces returns False.");
	cls_IntPatch_Intersection.def("NbPnts", (Standard_Integer (IntPatch_Intersection::*)() const ) &IntPatch_Intersection::NbPnts, "Returns the number of 'single' points.");
	cls_IntPatch_Intersection.def("Point", (const IntPatch_Point & (IntPatch_Intersection::*)(const Standard_Integer) const ) &IntPatch_Intersection::Point, "Returns the point of range Index. An exception is raised if Index<=0 or Index>NbPnt.", py::arg("Index"));
	cls_IntPatch_Intersection.def("NbLines", (Standard_Integer (IntPatch_Intersection::*)() const ) &IntPatch_Intersection::NbLines, "Returns the number of intersection lines.");
	cls_IntPatch_Intersection.def("Line", (const opencascade::handle<IntPatch_Line> & (IntPatch_Intersection::*)(const Standard_Integer) const ) &IntPatch_Intersection::Line, "Returns the line of range Index. An exception is raised if Index<=0 or Index>NbLine.", py::arg("Index"));
	cls_IntPatch_Intersection.def("SequenceOfLine", (const IntPatch_SequenceOfLine & (IntPatch_Intersection::*)() const ) &IntPatch_Intersection::SequenceOfLine, "None");
	// FIXME cls_IntPatch_Intersection.def("Dump", (void (IntPatch_Intersection::*)(const Standard_Integer, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &) const ) &IntPatch_Intersection::Dump, "Dump of each result line. Mode for more accurate dumps.", py::arg("Mode"), py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_ALine.hxx
	py::class_<IntPatch_ALine, opencascade::handle<IntPatch_ALine>, IntPatch_Line> cls_IntPatch_ALine(mod, "IntPatch_ALine", "Implementation of an intersection line described by a parametrised curve.");
	cls_IntPatch_ALine.def(py::init<const IntAna_Curve &, const Standard_Boolean, const IntSurf_TypeTrans, const IntSurf_TypeTrans>(), py::arg("C"), py::arg("Tang"), py::arg("Trans1"), py::arg("Trans2"));
	cls_IntPatch_ALine.def(py::init<const IntAna_Curve &, const Standard_Boolean, const IntSurf_Situation, const IntSurf_Situation>(), py::arg("C"), py::arg("Tang"), py::arg("Situ1"), py::arg("Situ2"));
	cls_IntPatch_ALine.def(py::init<const IntAna_Curve &, const Standard_Boolean>(), py::arg("C"), py::arg("Tang"));
	cls_IntPatch_ALine.def("AddVertex", (void (IntPatch_ALine::*)(const IntPatch_Point &)) &IntPatch_ALine::AddVertex, "To add a vertex in the list.", py::arg("Pnt"));
	cls_IntPatch_ALine.def("Replace", (void (IntPatch_ALine::*)(const Standard_Integer, const IntPatch_Point &)) &IntPatch_ALine::Replace, "Replaces the element of range Index in the list of points.", py::arg("Index"), py::arg("Pnt"));
	cls_IntPatch_ALine.def("SetFirstPoint", (void (IntPatch_ALine::*)(const Standard_Integer)) &IntPatch_ALine::SetFirstPoint, "None", py::arg("IndFirst"));
	cls_IntPatch_ALine.def("SetLastPoint", (void (IntPatch_ALine::*)(const Standard_Integer)) &IntPatch_ALine::SetLastPoint, "None", py::arg("IndLast"));
	cls_IntPatch_ALine.def("FirstParameter", (Standard_Real (IntPatch_ALine::*)(Standard_Boolean &) const ) &IntPatch_ALine::FirstParameter, "Returns the first parameter on the intersection line. If IsIncluded returns True, Value and D1 methods can be call with a parameter equal to FirstParamater. Otherwise, the parameter must be greater than FirstParameter.", py::arg("IsIncluded"));
	cls_IntPatch_ALine.def("LastParameter", (Standard_Real (IntPatch_ALine::*)(Standard_Boolean &) const ) &IntPatch_ALine::LastParameter, "Returns the last parameter on the intersection line. If IsIncluded returns True, Value and D1 methods can be call with a parameter equal to LastParamater. Otherwise, the parameter must be less than LastParameter.", py::arg("IsIncluded"));
	cls_IntPatch_ALine.def("Value", (gp_Pnt (IntPatch_ALine::*)(const Standard_Real)) &IntPatch_ALine::Value, "Returns the point of parameter U on the analytic intersection line.", py::arg("U"));
	cls_IntPatch_ALine.def("D1", (Standard_Boolean (IntPatch_ALine::*)(const Standard_Real, gp_Pnt &, gp_Vec &)) &IntPatch_ALine::D1, "Returns Standard_True when the derivative at parameter U is defined on the analytic intersection line. In that case, Du is the derivative. Returns Standard_False when it is not possible to evaluate the derivative. In both cases, P is the point at parameter U on the intersection.", py::arg("U"), py::arg("P"), py::arg("Du"));
	cls_IntPatch_ALine.def("FindParameter", (Standard_Boolean (IntPatch_ALine::*)(const gp_Pnt &, Standard_Real &) const ) &IntPatch_ALine::FindParameter, "Tries to find the parameter of the point P on the curve. If the method returns False, the 'projection' is impossible, and the value of Para is not significant. If the method returns True, Para is the parameter of the nearest intersection between the curve and the iso-theta containing P.", py::arg("P"), py::arg("Para"));
	cls_IntPatch_ALine.def("HasFirstPoint", (Standard_Boolean (IntPatch_ALine::*)() const ) &IntPatch_ALine::HasFirstPoint, "Returns True if the line has a known First point. This point is given by the method FirstPoint().");
	cls_IntPatch_ALine.def("HasLastPoint", (Standard_Boolean (IntPatch_ALine::*)() const ) &IntPatch_ALine::HasLastPoint, "Returns True if the line has a known Last point. This point is given by the method LastPoint().");
	cls_IntPatch_ALine.def("FirstPoint", (const IntPatch_Point & (IntPatch_ALine::*)() const ) &IntPatch_ALine::FirstPoint, "Returns the IntPoint corresponding to the FirstPoint. An exception is raised when HasFirstPoint returns False.");
	cls_IntPatch_ALine.def("LastPoint", (const IntPatch_Point & (IntPatch_ALine::*)() const ) &IntPatch_ALine::LastPoint, "Returns the IntPoint corresponding to the LastPoint. An exception is raised when HasLastPoint returns False.");
	cls_IntPatch_ALine.def("NbVertex", (Standard_Integer (IntPatch_ALine::*)() const ) &IntPatch_ALine::NbVertex, "None");
	cls_IntPatch_ALine.def("Vertex", (const IntPatch_Point & (IntPatch_ALine::*)(const Standard_Integer) const ) &IntPatch_ALine::Vertex, "Returns the vertex of range Index on the line.", py::arg("Index"));
	cls_IntPatch_ALine.def("ComputeVertexParameters", (void (IntPatch_ALine::*)(const Standard_Real)) &IntPatch_ALine::ComputeVertexParameters, "Set the parameters of all the vertex on the line. if a vertex is already in the line, its parameter is modified else a new point in the line is inserted.", py::arg("Tol"));
	cls_IntPatch_ALine.def("Curve", (const IntAna_Curve & (IntPatch_ALine::*)() const ) &IntPatch_ALine::Curve, "None");
	cls_IntPatch_ALine.def_static("get_type_name_", (const char * (*)()) &IntPatch_ALine::get_type_name, "None");
	cls_IntPatch_ALine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntPatch_ALine::get_type_descriptor, "None");
	cls_IntPatch_ALine.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntPatch_ALine::*)() const ) &IntPatch_ALine::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_PointLine.hxx
	py::class_<IntPatch_PointLine, opencascade::handle<IntPatch_PointLine>, IntPatch_Line> cls_IntPatch_PointLine(mod, "IntPatch_PointLine", "Definition of an intersection line between two surfaces. A line defined by a set of points (e.g. coming from a walking algorithm) as defined in the class WLine or RLine (Restriction line).");
	cls_IntPatch_PointLine.def("AddVertex", [](IntPatch_PointLine &self, const IntPatch_Point & a0) -> void { return self.AddVertex(a0); }, py::arg("Pnt"));
	cls_IntPatch_PointLine.def("AddVertex", (void (IntPatch_PointLine::*)(const IntPatch_Point &, const Standard_Boolean)) &IntPatch_PointLine::AddVertex, "Adds a vertex in the list. If theIsPrepend == TRUE the new vertex will be added before the first element of vertices sequence. Otherwise, to the end of the sequence", py::arg("Pnt"), py::arg("theIsPrepend"));
	cls_IntPatch_PointLine.def("NbPnts", (Standard_Integer (IntPatch_PointLine::*)() const ) &IntPatch_PointLine::NbPnts, "Returns the number of intersection points.");
	cls_IntPatch_PointLine.def("NbVertex", (Standard_Integer (IntPatch_PointLine::*)() const ) &IntPatch_PointLine::NbVertex, "Returns number of vertices (IntPatch_Point) of the line");
	cls_IntPatch_PointLine.def("Point", (const IntSurf_PntOn2S & (IntPatch_PointLine::*)(const Standard_Integer) const ) &IntPatch_PointLine::Point, "Returns the intersection point of range Index.", py::arg("Index"));
	cls_IntPatch_PointLine.def("Vertex", (const IntPatch_Point & (IntPatch_PointLine::*)(const Standard_Integer) const ) &IntPatch_PointLine::Vertex, "Returns the vertex of range Index on the line.", py::arg("Index"));
	cls_IntPatch_PointLine.def("ChangeVertex", (IntPatch_Point & (IntPatch_PointLine::*)(const Standard_Integer)) &IntPatch_PointLine::ChangeVertex, "Returns the vertex of range Index on the line.", py::arg("Index"));
	cls_IntPatch_PointLine.def("ClearVertexes", (void (IntPatch_PointLine::*)()) &IntPatch_PointLine::ClearVertexes, "Removes vertices from the line");
	cls_IntPatch_PointLine.def("RemoveVertex", (void (IntPatch_PointLine::*)(const Standard_Integer)) &IntPatch_PointLine::RemoveVertex, "Removes single vertex from the line", py::arg("theIndex"));
	cls_IntPatch_PointLine.def("Curve", (opencascade::handle<IntSurf_LineOn2S> (IntPatch_PointLine::*)() const ) &IntPatch_PointLine::Curve, "Returns set of intersection points");
	cls_IntPatch_PointLine.def_static("CurvatureRadiusOfIntersLine_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const IntSurf_PntOn2S &)) &IntPatch_PointLine::CurvatureRadiusOfIntersLine, "Returns the radius of curvature of the intersection line in given point. Returns negative value if computation is not possible.", py::arg("theS1"), py::arg("theS2"), py::arg("theUVPoint"));
	cls_IntPatch_PointLine.def_static("get_type_name_", (const char * (*)()) &IntPatch_PointLine::get_type_name, "None");
	cls_IntPatch_PointLine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntPatch_PointLine::get_type_descriptor, "None");
	cls_IntPatch_PointLine.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntPatch_PointLine::*)() const ) &IntPatch_PointLine::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_WLine.hxx
	py::class_<IntPatch_WLine, opencascade::handle<IntPatch_WLine>, IntPatch_PointLine> cls_IntPatch_WLine(mod, "IntPatch_WLine", "Definition of set of points as a result of the intersection between 2 parametrised patches.");
	cls_IntPatch_WLine.def(py::init<const opencascade::handle<IntSurf_LineOn2S> &, const Standard_Boolean, const IntSurf_TypeTrans, const IntSurf_TypeTrans>(), py::arg("Line"), py::arg("Tang"), py::arg("Trans1"), py::arg("Trans2"));
	cls_IntPatch_WLine.def(py::init<const opencascade::handle<IntSurf_LineOn2S> &, const Standard_Boolean, const IntSurf_Situation, const IntSurf_Situation>(), py::arg("Line"), py::arg("Tang"), py::arg("Situ1"), py::arg("Situ2"));
	cls_IntPatch_WLine.def(py::init<const opencascade::handle<IntSurf_LineOn2S> &, const Standard_Boolean>(), py::arg("Line"), py::arg("Tang"));
	cls_IntPatch_WLine.def("AddVertex", [](IntPatch_WLine &self, const IntPatch_Point & a0) -> void { return self.AddVertex(a0); }, py::arg("Pnt"));
	cls_IntPatch_WLine.def("AddVertex", (void (IntPatch_WLine::*)(const IntPatch_Point &, const Standard_Boolean)) &IntPatch_WLine::AddVertex, "Adds a vertex in the list. If theIsPrepend == TRUE the new vertex will be added before the first element of vertices sequence. Otherwise, to the end of the sequence", py::arg("Pnt"), py::arg("theIsPrepend"));
	cls_IntPatch_WLine.def("SetPoint", (void (IntPatch_WLine::*)(const Standard_Integer, const IntPatch_Point &)) &IntPatch_WLine::SetPoint, "Set the Point of index <Index> in the LineOn2S", py::arg("Index"), py::arg("Pnt"));
	cls_IntPatch_WLine.def("Replace", (void (IntPatch_WLine::*)(const Standard_Integer, const IntPatch_Point &)) &IntPatch_WLine::Replace, "Replaces the element of range Index in the list of points. The exception OutOfRange is raised when Index <= 0 or Index > NbVertex.", py::arg("Index"), py::arg("Pnt"));
	cls_IntPatch_WLine.def("SetFirstPoint", (void (IntPatch_WLine::*)(const Standard_Integer)) &IntPatch_WLine::SetFirstPoint, "None", py::arg("IndFirst"));
	cls_IntPatch_WLine.def("SetLastPoint", (void (IntPatch_WLine::*)(const Standard_Integer)) &IntPatch_WLine::SetLastPoint, "None", py::arg("IndLast"));
	cls_IntPatch_WLine.def("NbPnts", (Standard_Integer (IntPatch_WLine::*)() const ) &IntPatch_WLine::NbPnts, "Returns the number of intersection points.");
	cls_IntPatch_WLine.def("Point", (const IntSurf_PntOn2S & (IntPatch_WLine::*)(const Standard_Integer) const ) &IntPatch_WLine::Point, "Returns the intersection point of range Index.", py::arg("Index"));
	cls_IntPatch_WLine.def("HasFirstPoint", (Standard_Boolean (IntPatch_WLine::*)() const ) &IntPatch_WLine::HasFirstPoint, "Returns True if the line has a known First point. This point is given by the method FirstPoint().");
	cls_IntPatch_WLine.def("HasLastPoint", (Standard_Boolean (IntPatch_WLine::*)() const ) &IntPatch_WLine::HasLastPoint, "Returns True if the line has a known Last point. This point is given by the method LastPoint().");
	cls_IntPatch_WLine.def("FirstPoint", (const IntPatch_Point & (IntPatch_WLine::*)() const ) &IntPatch_WLine::FirstPoint, "Returns the Point corresponding to the FirstPoint.");
	cls_IntPatch_WLine.def("LastPoint", (const IntPatch_Point & (IntPatch_WLine::*)() const ) &IntPatch_WLine::LastPoint, "Returns the Point corresponding to the LastPoint.");
	cls_IntPatch_WLine.def("FirstPoint", (const IntPatch_Point & (IntPatch_WLine::*)(Standard_Integer &) const ) &IntPatch_WLine::FirstPoint, "Returns the Point corresponding to the FirstPoint. Indfirst is the index of the first in the list of vertices.", py::arg("Indfirst"));
	cls_IntPatch_WLine.def("LastPoint", (const IntPatch_Point & (IntPatch_WLine::*)(Standard_Integer &) const ) &IntPatch_WLine::LastPoint, "Returns the Point corresponding to the LastPoint. Indlast is the index of the last in the list of vertices.", py::arg("Indlast"));
	cls_IntPatch_WLine.def("NbVertex", (Standard_Integer (IntPatch_WLine::*)() const ) &IntPatch_WLine::NbVertex, "Returns number of vertices (IntPatch_Point) of the line");
	cls_IntPatch_WLine.def("Vertex", (const IntPatch_Point & (IntPatch_WLine::*)(const Standard_Integer) const ) &IntPatch_WLine::Vertex, "Returns the vertex of range Index on the line.", py::arg("Index"));
	cls_IntPatch_WLine.def("ChangeVertex", (IntPatch_Point & (IntPatch_WLine::*)(const Standard_Integer)) &IntPatch_WLine::ChangeVertex, "Returns the vertex of range Index on the line.", py::arg("Index"));
	cls_IntPatch_WLine.def("ComputeVertexParameters", (void (IntPatch_WLine::*)(const Standard_Real)) &IntPatch_WLine::ComputeVertexParameters, "Set the parameters of all the vertex on the line. if a vertex is already in the line, its parameter is modified else a new point in the line is inserted.", py::arg("Tol"));
	cls_IntPatch_WLine.def("Curve", (opencascade::handle<IntSurf_LineOn2S> (IntPatch_WLine::*)() const ) &IntPatch_WLine::Curve, "Returns set of intersection points");
	cls_IntPatch_WLine.def("IsOutSurf1Box", (Standard_Boolean (IntPatch_WLine::*)(const gp_Pnt2d &)) &IntPatch_WLine::IsOutSurf1Box, "None", py::arg("P1"));
	cls_IntPatch_WLine.def("IsOutSurf2Box", (Standard_Boolean (IntPatch_WLine::*)(const gp_Pnt2d &)) &IntPatch_WLine::IsOutSurf2Box, "None", py::arg("P1"));
	cls_IntPatch_WLine.def("IsOutBox", (Standard_Boolean (IntPatch_WLine::*)(const gp_Pnt &)) &IntPatch_WLine::IsOutBox, "None", py::arg("P"));
	cls_IntPatch_WLine.def("SetPeriod", (void (IntPatch_WLine::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_WLine::SetPeriod, "None", py::arg("pu1"), py::arg("pv1"), py::arg("pu2"), py::arg("pv2"));
	cls_IntPatch_WLine.def("U1Period", (Standard_Real (IntPatch_WLine::*)() const ) &IntPatch_WLine::U1Period, "None");
	cls_IntPatch_WLine.def("V1Period", (Standard_Real (IntPatch_WLine::*)() const ) &IntPatch_WLine::V1Period, "None");
	cls_IntPatch_WLine.def("U2Period", (Standard_Real (IntPatch_WLine::*)() const ) &IntPatch_WLine::U2Period, "None");
	cls_IntPatch_WLine.def("V2Period", (Standard_Real (IntPatch_WLine::*)() const ) &IntPatch_WLine::V2Period, "None");
	cls_IntPatch_WLine.def("SetArcOnS1", (void (IntPatch_WLine::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_WLine::SetArcOnS1, "None", py::arg("A"));
	cls_IntPatch_WLine.def("HasArcOnS1", (Standard_Boolean (IntPatch_WLine::*)() const ) &IntPatch_WLine::HasArcOnS1, "None");
	cls_IntPatch_WLine.def("GetArcOnS1", (const opencascade::handle<Adaptor2d_HCurve2d> & (IntPatch_WLine::*)() const ) &IntPatch_WLine::GetArcOnS1, "None");
	cls_IntPatch_WLine.def("SetArcOnS2", (void (IntPatch_WLine::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_WLine::SetArcOnS2, "None", py::arg("A"));
	cls_IntPatch_WLine.def("HasArcOnS2", (Standard_Boolean (IntPatch_WLine::*)() const ) &IntPatch_WLine::HasArcOnS2, "None");
	cls_IntPatch_WLine.def("GetArcOnS2", (const opencascade::handle<Adaptor2d_HCurve2d> & (IntPatch_WLine::*)() const ) &IntPatch_WLine::GetArcOnS2, "None");
	cls_IntPatch_WLine.def("ClearVertexes", (void (IntPatch_WLine::*)()) &IntPatch_WLine::ClearVertexes, "Removes vertices from the line (i.e. cleans svtx member)");
	cls_IntPatch_WLine.def("RemoveVertex", (void (IntPatch_WLine::*)(const Standard_Integer)) &IntPatch_WLine::RemoveVertex, "Removes single vertex from the line", py::arg("theIndex"));
	cls_IntPatch_WLine.def("InsertVertexBefore", (void (IntPatch_WLine::*)(const Standard_Integer, const IntPatch_Point &)) &IntPatch_WLine::InsertVertexBefore, "None", py::arg("theIndex"), py::arg("thePnt"));
	// FIXME cls_IntPatch_WLine.def("Dump", (void (IntPatch_WLine::*)(const Standard_Integer) const ) &IntPatch_WLine::Dump, "if (theMode == 0) then prints the information about WLine if (theMode == 1) then prints the list of 3d-points if (theMode == 2) then prints the list of 2d-points on the 1st surface Otherwise, prints list of 2d-points on the 2nd surface", py::arg("theMode"));
	cls_IntPatch_WLine.def("EnablePurging", (void (IntPatch_WLine::*)(const Standard_Boolean)) &IntPatch_WLine::EnablePurging, "Allows or forbides purging of existing WLine", py::arg("theIsEnabled"));
	cls_IntPatch_WLine.def("IsPurgingAllowed", (Standard_Boolean (IntPatch_WLine::*)()) &IntPatch_WLine::IsPurgingAllowed, "Returns TRUE if purging is allowed or forbiden for existing WLine");
	cls_IntPatch_WLine.def_static("get_type_name_", (const char * (*)()) &IntPatch_WLine::get_type_name, "None");
	cls_IntPatch_WLine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntPatch_WLine::get_type_descriptor, "None");
	cls_IntPatch_WLine.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntPatch_WLine::*)() const ) &IntPatch_WLine::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_GLine.hxx
	py::class_<IntPatch_GLine, opencascade::handle<IntPatch_GLine>, IntPatch_Line> cls_IntPatch_GLine(mod, "IntPatch_GLine", "Implementation of an intersection line represented by a conic.");
	cls_IntPatch_GLine.def(py::init<const gp_Lin &, const Standard_Boolean, const IntSurf_TypeTrans, const IntSurf_TypeTrans>(), py::arg("L"), py::arg("Tang"), py::arg("Trans1"), py::arg("Trans2"));
	cls_IntPatch_GLine.def(py::init<const gp_Lin &, const Standard_Boolean, const IntSurf_Situation, const IntSurf_Situation>(), py::arg("L"), py::arg("Tang"), py::arg("Situ1"), py::arg("Situ2"));
	cls_IntPatch_GLine.def(py::init<const gp_Lin &, const Standard_Boolean>(), py::arg("L"), py::arg("Tang"));
	cls_IntPatch_GLine.def(py::init<const gp_Circ &, const Standard_Boolean, const IntSurf_TypeTrans, const IntSurf_TypeTrans>(), py::arg("C"), py::arg("Tang"), py::arg("Trans1"), py::arg("Trans2"));
	cls_IntPatch_GLine.def(py::init<const gp_Circ &, const Standard_Boolean, const IntSurf_Situation, const IntSurf_Situation>(), py::arg("C"), py::arg("Tang"), py::arg("Situ1"), py::arg("Situ2"));
	cls_IntPatch_GLine.def(py::init<const gp_Circ &, const Standard_Boolean>(), py::arg("C"), py::arg("Tang"));
	cls_IntPatch_GLine.def(py::init<const gp_Elips &, const Standard_Boolean, const IntSurf_TypeTrans, const IntSurf_TypeTrans>(), py::arg("E"), py::arg("Tang"), py::arg("Trans1"), py::arg("Trans2"));
	cls_IntPatch_GLine.def(py::init<const gp_Elips &, const Standard_Boolean, const IntSurf_Situation, const IntSurf_Situation>(), py::arg("E"), py::arg("Tang"), py::arg("Situ1"), py::arg("Situ2"));
	cls_IntPatch_GLine.def(py::init<const gp_Elips &, const Standard_Boolean>(), py::arg("E"), py::arg("Tang"));
	cls_IntPatch_GLine.def(py::init<const gp_Parab &, const Standard_Boolean, const IntSurf_TypeTrans, const IntSurf_TypeTrans>(), py::arg("P"), py::arg("Tang"), py::arg("Trans1"), py::arg("Trans2"));
	cls_IntPatch_GLine.def(py::init<const gp_Parab &, const Standard_Boolean, const IntSurf_Situation, const IntSurf_Situation>(), py::arg("P"), py::arg("Tang"), py::arg("Situ1"), py::arg("Situ2"));
	cls_IntPatch_GLine.def(py::init<const gp_Parab &, const Standard_Boolean>(), py::arg("P"), py::arg("Tang"));
	cls_IntPatch_GLine.def(py::init<const gp_Hypr &, const Standard_Boolean, const IntSurf_TypeTrans, const IntSurf_TypeTrans>(), py::arg("H"), py::arg("Tang"), py::arg("Trans1"), py::arg("Trans2"));
	cls_IntPatch_GLine.def(py::init<const gp_Hypr &, const Standard_Boolean, const IntSurf_Situation, const IntSurf_Situation>(), py::arg("H"), py::arg("Tang"), py::arg("Situ1"), py::arg("Situ2"));
	cls_IntPatch_GLine.def(py::init<const gp_Hypr &, const Standard_Boolean>(), py::arg("H"), py::arg("Tang"));
	cls_IntPatch_GLine.def("AddVertex", (void (IntPatch_GLine::*)(const IntPatch_Point &)) &IntPatch_GLine::AddVertex, "To add a vertex in the list.", py::arg("Pnt"));
	cls_IntPatch_GLine.def("Replace", (void (IntPatch_GLine::*)(const Standard_Integer, const IntPatch_Point &)) &IntPatch_GLine::Replace, "To replace the element of range Index in the list of points.", py::arg("Index"), py::arg("Pnt"));
	cls_IntPatch_GLine.def("SetFirstPoint", (void (IntPatch_GLine::*)(const Standard_Integer)) &IntPatch_GLine::SetFirstPoint, "None", py::arg("IndFirst"));
	cls_IntPatch_GLine.def("SetLastPoint", (void (IntPatch_GLine::*)(const Standard_Integer)) &IntPatch_GLine::SetLastPoint, "None", py::arg("IndLast"));
	cls_IntPatch_GLine.def("Line", (gp_Lin (IntPatch_GLine::*)() const ) &IntPatch_GLine::Line, "Returns the Lin from gp corresponding to the intersection when ArcType returns IntPatch_Line.");
	cls_IntPatch_GLine.def("Circle", (gp_Circ (IntPatch_GLine::*)() const ) &IntPatch_GLine::Circle, "Returns the Circ from gp corrsponding to the intersection when ArcType returns IntPatch_Circle.");
	cls_IntPatch_GLine.def("Ellipse", (gp_Elips (IntPatch_GLine::*)() const ) &IntPatch_GLine::Ellipse, "Returns the Elips from gp corrsponding to the intersection when ArcType returns IntPatch_Ellipse.");
	cls_IntPatch_GLine.def("Parabola", (gp_Parab (IntPatch_GLine::*)() const ) &IntPatch_GLine::Parabola, "Returns the Parab from gp corrsponding to the intersection when ArcType returns IntPatch_Parabola.");
	cls_IntPatch_GLine.def("Hyperbola", (gp_Hypr (IntPatch_GLine::*)() const ) &IntPatch_GLine::Hyperbola, "Returns the Hypr from gp corrsponding to the intersection when ArcType returns IntPatch_Hyperbola.");
	cls_IntPatch_GLine.def("HasFirstPoint", (Standard_Boolean (IntPatch_GLine::*)() const ) &IntPatch_GLine::HasFirstPoint, "Returns True if the line has a known First point. This point is given by the method FirstPoint().");
	cls_IntPatch_GLine.def("HasLastPoint", (Standard_Boolean (IntPatch_GLine::*)() const ) &IntPatch_GLine::HasLastPoint, "Returns True if the line has a known Last point. This point is given by the method LastPoint().");
	cls_IntPatch_GLine.def("FirstPoint", (const IntPatch_Point & (IntPatch_GLine::*)() const ) &IntPatch_GLine::FirstPoint, "Returns the IntPoint corresponding to the FirstPoint. An exception is raised when HasFirstPoint returns False.");
	cls_IntPatch_GLine.def("LastPoint", (const IntPatch_Point & (IntPatch_GLine::*)() const ) &IntPatch_GLine::LastPoint, "Returns the IntPoint corresponding to the LastPoint. An exception is raised when HasLastPoint returns False.");
	cls_IntPatch_GLine.def("NbVertex", (Standard_Integer (IntPatch_GLine::*)() const ) &IntPatch_GLine::NbVertex, "None");
	cls_IntPatch_GLine.def("Vertex", (const IntPatch_Point & (IntPatch_GLine::*)(const Standard_Integer) const ) &IntPatch_GLine::Vertex, "Returns the vertex of range Index on the line.", py::arg("Index"));
	cls_IntPatch_GLine.def("ComputeVertexParameters", (void (IntPatch_GLine::*)(const Standard_Real)) &IntPatch_GLine::ComputeVertexParameters, "Set the parameters of all the vertex on the line. if a vertex is already in the line, its parameter is modified else a new point in the line is inserted.", py::arg("Tol"));
	cls_IntPatch_GLine.def_static("get_type_name_", (const char * (*)()) &IntPatch_GLine::get_type_name, "None");
	cls_IntPatch_GLine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntPatch_GLine::get_type_descriptor, "None");
	cls_IntPatch_GLine.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntPatch_GLine::*)() const ) &IntPatch_GLine::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_ALineToWLine.hxx
	py::class_<IntPatch_ALineToWLine, std::unique_ptr<IntPatch_ALineToWLine, Deleter<IntPatch_ALineToWLine>>> cls_IntPatch_ALineToWLine(mod, "IntPatch_ALineToWLine", "None");
	cls_IntPatch_ALineToWLine.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("theS1"), py::arg("theS2"));
	cls_IntPatch_ALineToWLine.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer>(), py::arg("theS1"), py::arg("theS2"), py::arg("theNbPoints"));
	cls_IntPatch_ALineToWLine.def("SetTolOpenDomain", (void (IntPatch_ALineToWLine::*)(const Standard_Real)) &IntPatch_ALineToWLine::SetTolOpenDomain, "None", py::arg("aT"));
	cls_IntPatch_ALineToWLine.def("TolOpenDomain", (Standard_Real (IntPatch_ALineToWLine::*)() const ) &IntPatch_ALineToWLine::TolOpenDomain, "None");
	cls_IntPatch_ALineToWLine.def("SetTolTransition", (void (IntPatch_ALineToWLine::*)(const Standard_Real)) &IntPatch_ALineToWLine::SetTolTransition, "None", py::arg("aT"));
	cls_IntPatch_ALineToWLine.def("TolTransition", (Standard_Real (IntPatch_ALineToWLine::*)() const ) &IntPatch_ALineToWLine::TolTransition, "None");
	cls_IntPatch_ALineToWLine.def("SetTol3D", (void (IntPatch_ALineToWLine::*)(const Standard_Real)) &IntPatch_ALineToWLine::SetTol3D, "None", py::arg("aT"));
	cls_IntPatch_ALineToWLine.def("Tol3D", (Standard_Real (IntPatch_ALineToWLine::*)() const ) &IntPatch_ALineToWLine::Tol3D, "None");
	cls_IntPatch_ALineToWLine.def("MakeWLine", (void (IntPatch_ALineToWLine::*)(const opencascade::handle<IntPatch_ALine> &, IntPatch_SequenceOfLine &) const ) &IntPatch_ALineToWLine::MakeWLine, "Converts aline to the set of Walking-lines and adds them in theLines.", py::arg("aline"), py::arg("theLines"));
	cls_IntPatch_ALineToWLine.def("MakeWLine", (void (IntPatch_ALineToWLine::*)(const opencascade::handle<IntPatch_ALine> &, const Standard_Real, const Standard_Real, IntPatch_SequenceOfLine &) const ) &IntPatch_ALineToWLine::MakeWLine, "Converts aline (limitted by paraminf and paramsup) to the set of Walking-lines and adds them in theLines.", py::arg("aline"), py::arg("paraminf"), py::arg("paramsup"), py::arg("theLines"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_ArcFunction.hxx
	py::class_<IntPatch_ArcFunction, std::unique_ptr<IntPatch_ArcFunction, Deleter<IntPatch_ArcFunction>>, math_FunctionWithDerivative> cls_IntPatch_ArcFunction(mod, "IntPatch_ArcFunction", "None");
	cls_IntPatch_ArcFunction.def(py::init<>());
	cls_IntPatch_ArcFunction.def("SetQuadric", (void (IntPatch_ArcFunction::*)(const IntSurf_Quadric &)) &IntPatch_ArcFunction::SetQuadric, "None", py::arg("Q"));
	cls_IntPatch_ArcFunction.def("Set", (void (IntPatch_ArcFunction::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_ArcFunction::Set, "None", py::arg("A"));
	cls_IntPatch_ArcFunction.def("Set", (void (IntPatch_ArcFunction::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &IntPatch_ArcFunction::Set, "None", py::arg("S"));
	cls_IntPatch_ArcFunction.def("Value", (Standard_Boolean (IntPatch_ArcFunction::*)(const Standard_Real, Standard_Real &)) &IntPatch_ArcFunction::Value, "None", py::arg("X"), py::arg("F"));
	cls_IntPatch_ArcFunction.def("Derivative", (Standard_Boolean (IntPatch_ArcFunction::*)(const Standard_Real, Standard_Real &)) &IntPatch_ArcFunction::Derivative, "None", py::arg("X"), py::arg("D"));
	cls_IntPatch_ArcFunction.def("Values", (Standard_Boolean (IntPatch_ArcFunction::*)(const Standard_Real, Standard_Real &, Standard_Real &)) &IntPatch_ArcFunction::Values, "None", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_IntPatch_ArcFunction.def("NbSamples", (Standard_Integer (IntPatch_ArcFunction::*)() const ) &IntPatch_ArcFunction::NbSamples, "None");
	cls_IntPatch_ArcFunction.def("GetStateNumber", (Standard_Integer (IntPatch_ArcFunction::*)()) &IntPatch_ArcFunction::GetStateNumber, "None");
	cls_IntPatch_ArcFunction.def("Valpoint", (const gp_Pnt & (IntPatch_ArcFunction::*)(const Standard_Integer) const ) &IntPatch_ArcFunction::Valpoint, "None", py::arg("Index"));
	cls_IntPatch_ArcFunction.def("Quadric", (const IntSurf_Quadric & (IntPatch_ArcFunction::*)() const ) &IntPatch_ArcFunction::Quadric, "None");
	cls_IntPatch_ArcFunction.def("Arc", (const opencascade::handle<Adaptor2d_HCurve2d> & (IntPatch_ArcFunction::*)() const ) &IntPatch_ArcFunction::Arc, "None");
	cls_IntPatch_ArcFunction.def("Surface", (const opencascade::handle<Adaptor3d_HSurface> & (IntPatch_ArcFunction::*)() const ) &IntPatch_ArcFunction::Surface, "None");
	cls_IntPatch_ArcFunction.def("LastComputedPoint", (const gp_Pnt & (IntPatch_ArcFunction::*)() const ) &IntPatch_ArcFunction::LastComputedPoint, "Returns the point, which has been computed while the last calling Value() method");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_CSFunction.hxx
	py::class_<IntPatch_CSFunction, std::unique_ptr<IntPatch_CSFunction, Deleter<IntPatch_CSFunction>>, math_FunctionSetWithDerivatives> cls_IntPatch_CSFunction(mod, "IntPatch_CSFunction", "this function is associated to the intersection between a curve on surface and a surface .");
	cls_IntPatch_CSFunction.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("S1"), py::arg("C"), py::arg("S2"));
	cls_IntPatch_CSFunction.def("NbVariables", (Standard_Integer (IntPatch_CSFunction::*)() const ) &IntPatch_CSFunction::NbVariables, "None");
	cls_IntPatch_CSFunction.def("NbEquations", (Standard_Integer (IntPatch_CSFunction::*)() const ) &IntPatch_CSFunction::NbEquations, "None");
	cls_IntPatch_CSFunction.def("Value", (Standard_Boolean (IntPatch_CSFunction::*)(const math_Vector &, math_Vector &)) &IntPatch_CSFunction::Value, "None", py::arg("X"), py::arg("F"));
	cls_IntPatch_CSFunction.def("Derivatives", (Standard_Boolean (IntPatch_CSFunction::*)(const math_Vector &, math_Matrix &)) &IntPatch_CSFunction::Derivatives, "None", py::arg("X"), py::arg("D"));
	cls_IntPatch_CSFunction.def("Values", (Standard_Boolean (IntPatch_CSFunction::*)(const math_Vector &, math_Vector &, math_Matrix &)) &IntPatch_CSFunction::Values, "None", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_IntPatch_CSFunction.def("Point", (const gp_Pnt & (IntPatch_CSFunction::*)() const ) &IntPatch_CSFunction::Point, "None");
	cls_IntPatch_CSFunction.def("Root", (Standard_Real (IntPatch_CSFunction::*)() const ) &IntPatch_CSFunction::Root, "None");
	cls_IntPatch_CSFunction.def("AuxillarSurface", (const opencascade::handle<Adaptor3d_HSurface> & (IntPatch_CSFunction::*)() const ) &IntPatch_CSFunction::AuxillarSurface, "None");
	cls_IntPatch_CSFunction.def("AuxillarCurve", (const opencascade::handle<Adaptor2d_HCurve2d> & (IntPatch_CSFunction::*)() const ) &IntPatch_CSFunction::AuxillarCurve, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_HCurve2dTool.hxx
	py::class_<IntPatch_HCurve2dTool, std::unique_ptr<IntPatch_HCurve2dTool, Deleter<IntPatch_HCurve2dTool>>> cls_IntPatch_HCurve2dTool(mod, "IntPatch_HCurve2dTool", "None");
	cls_IntPatch_HCurve2dTool.def(py::init<>());
	cls_IntPatch_HCurve2dTool.def_static("FirstParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HCurve2dTool::FirstParameter, "None", py::arg("C"));
	cls_IntPatch_HCurve2dTool.def_static("LastParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HCurve2dTool::LastParameter, "None", py::arg("C"));
	cls_IntPatch_HCurve2dTool.def_static("Continuity_", (GeomAbs_Shape (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HCurve2dTool::Continuity, "None", py::arg("C"));
	cls_IntPatch_HCurve2dTool.def_static("NbIntervals_", (Standard_Integer (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const GeomAbs_Shape)) &IntPatch_HCurve2dTool::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(myclass) >= <S>", py::arg("C"), py::arg("S"));
	cls_IntPatch_HCurve2dTool.def_static("Intervals_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &IntPatch_HCurve2dTool::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("C"), py::arg("T"), py::arg("S"));
	cls_IntPatch_HCurve2dTool.def_static("IsClosed_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HCurve2dTool::IsClosed, "None", py::arg("C"));
	cls_IntPatch_HCurve2dTool.def_static("IsPeriodic_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HCurve2dTool::IsPeriodic, "None", py::arg("C"));
	cls_IntPatch_HCurve2dTool.def_static("Period_", (Standard_Real (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HCurve2dTool::Period, "None", py::arg("C"));
	cls_IntPatch_HCurve2dTool.def_static("Value_", (gp_Pnt2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real)) &IntPatch_HCurve2dTool::Value, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"));
	cls_IntPatch_HCurve2dTool.def_static("D0_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, gp_Pnt2d &)) &IntPatch_HCurve2dTool::D0, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"), py::arg("P"));
	cls_IntPatch_HCurve2dTool.def_static("D1_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &)) &IntPatch_HCurve2dTool::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V"));
	cls_IntPatch_HCurve2dTool.def_static("D2_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &)) &IntPatch_HCurve2dTool::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_IntPatch_HCurve2dTool.def_static("D3_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &)) &IntPatch_HCurve2dTool::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_IntPatch_HCurve2dTool.def_static("DN_", (gp_Vec2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const Standard_Integer)) &IntPatch_HCurve2dTool::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("C"), py::arg("U"), py::arg("N"));
	cls_IntPatch_HCurve2dTool.def_static("Resolution_", (Standard_Real (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real)) &IntPatch_HCurve2dTool::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("C"), py::arg("R3d"));
	cls_IntPatch_HCurve2dTool.def_static("GetType_", (GeomAbs_CurveType (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HCurve2dTool::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.", py::arg("C"));
	cls_IntPatch_HCurve2dTool.def_static("Line_", (gp_Lin2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HCurve2dTool::Line, "None", py::arg("C"));
	cls_IntPatch_HCurve2dTool.def_static("Circle_", (gp_Circ2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HCurve2dTool::Circle, "None", py::arg("C"));
	cls_IntPatch_HCurve2dTool.def_static("Ellipse_", (gp_Elips2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HCurve2dTool::Ellipse, "None", py::arg("C"));
	cls_IntPatch_HCurve2dTool.def_static("Hyperbola_", (gp_Hypr2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HCurve2dTool::Hyperbola, "None", py::arg("C"));
	cls_IntPatch_HCurve2dTool.def_static("Parabola_", (gp_Parab2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HCurve2dTool::Parabola, "None", py::arg("C"));
	cls_IntPatch_HCurve2dTool.def_static("Bezier_", (opencascade::handle<Geom2d_BezierCurve> (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HCurve2dTool::Bezier, "None", py::arg("C"));
	cls_IntPatch_HCurve2dTool.def_static("BSpline_", (opencascade::handle<Geom2d_BSplineCurve> (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HCurve2dTool::BSpline, "None", py::arg("C"));
	cls_IntPatch_HCurve2dTool.def_static("NbSamples_", (Standard_Integer (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const Standard_Real)) &IntPatch_HCurve2dTool::NbSamples, "None", py::arg("C"), py::arg("U0"), py::arg("U1"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_CurvIntSurf.hxx
	py::class_<IntPatch_CurvIntSurf, std::unique_ptr<IntPatch_CurvIntSurf, Deleter<IntPatch_CurvIntSurf>>> cls_IntPatch_CurvIntSurf(mod, "IntPatch_CurvIntSurf", "None");
	cls_IntPatch_CurvIntSurf.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const IntPatch_CSFunction &, const Standard_Real>(), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("F"), py::arg("TolTangency"));
	cls_IntPatch_CurvIntSurf.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const IntPatch_CSFunction &, const Standard_Real, const Standard_Real>(), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("F"), py::arg("TolTangency"), py::arg("MarginCoef"));
	cls_IntPatch_CurvIntSurf.def(py::init<const IntPatch_CSFunction &, const Standard_Real>(), py::arg("F"), py::arg("TolTangency"));
	cls_IntPatch_CurvIntSurf.def("Perform", (void (IntPatch_CurvIntSurf::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_FunctionSetRoot &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_CurvIntSurf::Perform, "compute the solution it's possible to write to optimize: IntImp_IntCS inter(S1,C1,Toltangency) math_FunctionSetRoot rsnld(Inter.function()) while ...{ u=... v=... w=... inter.Perform(u,v,w,rsnld) } or IntImp_IntCS inter(Toltangency) inter.SetSurface(S); math_FunctionSetRoot rsnld(Inter.function()) while ...{ C=... inter.SetCurve(C); u=... v=... w=... inter.Perform(u,v,w,rsnld) }", py::arg("U"), py::arg("V"), py::arg("W"), py::arg("Rsnld"), py::arg("u0"), py::arg("v0"), py::arg("u1"), py::arg("v1"), py::arg("w0"), py::arg("w1"));
	cls_IntPatch_CurvIntSurf.def("IsDone", (Standard_Boolean (IntPatch_CurvIntSurf::*)() const ) &IntPatch_CurvIntSurf::IsDone, "Returns TRUE if the creation completed without failure.");
	cls_IntPatch_CurvIntSurf.def("IsEmpty", (Standard_Boolean (IntPatch_CurvIntSurf::*)() const ) &IntPatch_CurvIntSurf::IsEmpty, "None");
	cls_IntPatch_CurvIntSurf.def("Point", (const gp_Pnt & (IntPatch_CurvIntSurf::*)() const ) &IntPatch_CurvIntSurf::Point, "returns the intersection point The exception NotDone is raised if IsDone is false. The exception DomainError is raised if IsEmpty is true.");
	cls_IntPatch_CurvIntSurf.def("ParameterOnCurve", (Standard_Real (IntPatch_CurvIntSurf::*)() const ) &IntPatch_CurvIntSurf::ParameterOnCurve, "None");
	cls_IntPatch_CurvIntSurf.def("ParameterOnSurface", (void (IntPatch_CurvIntSurf::*)(Standard_Real &, Standard_Real &) const ) &IntPatch_CurvIntSurf::ParameterOnSurface, "None", py::arg("U"), py::arg("V"));
	cls_IntPatch_CurvIntSurf.def("Function", (IntPatch_CSFunction & (IntPatch_CurvIntSurf::*)()) &IntPatch_CurvIntSurf::Function, "return the math function which is used to compute the intersection");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_HInterTool.hxx
	py::class_<IntPatch_HInterTool, std::unique_ptr<IntPatch_HInterTool, Deleter<IntPatch_HInterTool>>> cls_IntPatch_HInterTool(mod, "IntPatch_HInterTool", "Tool for the intersection between 2 surfaces. Regroupe pour l instant les methodes hors Adaptor3d...");
	cls_IntPatch_HInterTool.def(py::init<>());
	cls_IntPatch_HInterTool.def_static("SingularOnUMin_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &IntPatch_HInterTool::SingularOnUMin, "None", py::arg("S"));
	cls_IntPatch_HInterTool.def_static("SingularOnUMax_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &IntPatch_HInterTool::SingularOnUMax, "None", py::arg("S"));
	cls_IntPatch_HInterTool.def_static("SingularOnVMin_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &IntPatch_HInterTool::SingularOnVMin, "None", py::arg("S"));
	cls_IntPatch_HInterTool.def_static("SingularOnVMax_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &IntPatch_HInterTool::SingularOnVMax, "None", py::arg("S"));
	cls_IntPatch_HInterTool.def_static("NbSamplesU_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real)) &IntPatch_HInterTool::NbSamplesU, "None", py::arg("S"), py::arg("u1"), py::arg("u2"));
	cls_IntPatch_HInterTool.def_static("NbSamplesV_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real)) &IntPatch_HInterTool::NbSamplesV, "None", py::arg("S"), py::arg("v1"), py::arg("v2"));
	cls_IntPatch_HInterTool.def("NbSamplePoints", (Standard_Integer (IntPatch_HInterTool::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &IntPatch_HInterTool::NbSamplePoints, "None", py::arg("S"));
	cls_IntPatch_HInterTool.def("SamplePoint", (void (IntPatch_HInterTool::*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, Standard_Real &, Standard_Real &) const ) &IntPatch_HInterTool::SamplePoint, "None", py::arg("S"), py::arg("Index"), py::arg("U"), py::arg("V"));
	cls_IntPatch_HInterTool.def_static("HasBeenSeen_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HInterTool::HasBeenSeen, "Returns True if all the intersection point and edges are known on the Arc. The intersection point are given as vertices. The intersection edges are given as intervals between two vertices.", py::arg("C"));
	cls_IntPatch_HInterTool.def_static("NbSamplesOnArc_", (Standard_Integer (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HInterTool::NbSamplesOnArc, "returns the number of points which is used to make a sample on the arc. this number is a function of the Surface and the CurveOnSurface complexity.", py::arg("A"));
	cls_IntPatch_HInterTool.def_static("Bounds_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, Standard_Real &, Standard_Real &)) &IntPatch_HInterTool::Bounds, "Returns the parametric limits on the arc C. These limits must be finite : they are either the real limits of the arc, for a finite arc, or a bounding box for an infinite arc.", py::arg("C"), py::arg("Ufirst"), py::arg("Ulast"));
	cls_IntPatch_HInterTool.def_static("Project_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const gp_Pnt2d &, Standard_Real &, gp_Pnt2d &)) &IntPatch_HInterTool::Project, "Projects the point P on the arc C. If the methods returns Standard_True, the projection is successful, and Paramproj is the parameter on the arc of the projected point, Ptproj is the projected Point. If the method returns Standard_False, Param proj and Ptproj are not significant.", py::arg("C"), py::arg("P"), py::arg("Paramproj"), py::arg("Ptproj"));
	cls_IntPatch_HInterTool.def_static("Tolerance_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HVertex> &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HInterTool::Tolerance, "Returns the parametric tolerance used to consider that the vertex and another point meet, i-e if Abs(parameter(Vertex) - parameter(OtherPnt))<= Tolerance, the points are 'merged'.", py::arg("V"), py::arg("C"));
	cls_IntPatch_HInterTool.def_static("Parameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HVertex> &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HInterTool::Parameter, "Returns the parameter of the vertex V on the arc A.", py::arg("V"), py::arg("C"));
	cls_IntPatch_HInterTool.def_static("NbPoints_", (Standard_Integer (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HInterTool::NbPoints, "Returns the number of intersection points on the arc A.", py::arg("C"));
	cls_IntPatch_HInterTool.def_static("Value_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Integer, gp_Pnt &, Standard_Real &, Standard_Real &)) &IntPatch_HInterTool::Value, "Returns the value (Pt), the tolerance (Tol), and the parameter (U) on the arc A , of the intersection point of range Index.", py::arg("C"), py::arg("Index"), py::arg("Pt"), py::arg("Tol"), py::arg("U"));
	cls_IntPatch_HInterTool.def_static("IsVertex_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Integer)) &IntPatch_HInterTool::IsVertex, "Returns True if the intersection point of range Index corresponds with a vertex on the arc A.", py::arg("C"), py::arg("Index"));
	cls_IntPatch_HInterTool.def_static("Vertex_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Integer, opencascade::handle<Adaptor3d_HVertex> &)) &IntPatch_HInterTool::Vertex, "When IsVertex returns True, this method returns the vertex on the arc A.", py::arg("C"), py::arg("Index"), py::arg("V"));
	cls_IntPatch_HInterTool.def_static("NbSegments_", (Standard_Integer (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HInterTool::NbSegments, "returns the number of part of A solution of the of intersection problem.", py::arg("C"));
	cls_IntPatch_HInterTool.def_static("HasFirstPoint_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Integer, Standard_Integer &)) &IntPatch_HInterTool::HasFirstPoint, "Returns True when the segment of range Index is not open at the left side. In that case, IndFirst is the range in the list intersection points (see NbPoints) of the one which defines the left bound of the segment. Otherwise, the method has to return False, and IndFirst has no meaning.", py::arg("C"), py::arg("Index"), py::arg("IndFirst"));
	cls_IntPatch_HInterTool.def_static("HasLastPoint_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Integer, Standard_Integer &)) &IntPatch_HInterTool::HasLastPoint, "Returns True when the segment of range Index is not open at the right side. In that case, IndLast is the range in the list intersection points (see NbPoints) of the one which defines the right bound of the segment. Otherwise, the method has to return False, and IndLast has no meaning.", py::arg("C"), py::arg("Index"), py::arg("IndLast"));
	cls_IntPatch_HInterTool.def_static("IsAllSolution_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HInterTool::IsAllSolution, "Returns True when the whole restriction is solution of the intersection problem.", py::arg("C"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_ThePathPointOfTheSOnBounds.hxx
	py::class_<IntPatch_ThePathPointOfTheSOnBounds, std::unique_ptr<IntPatch_ThePathPointOfTheSOnBounds, Deleter<IntPatch_ThePathPointOfTheSOnBounds>>> cls_IntPatch_ThePathPointOfTheSOnBounds(mod, "IntPatch_ThePathPointOfTheSOnBounds", "None");
	cls_IntPatch_ThePathPointOfTheSOnBounds.def(py::init<>());
	cls_IntPatch_ThePathPointOfTheSOnBounds.def(py::init<const gp_Pnt &, const Standard_Real, const opencascade::handle<Adaptor3d_HVertex> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real>(), py::arg("P"), py::arg("Tol"), py::arg("V"), py::arg("A"), py::arg("Parameter"));
	cls_IntPatch_ThePathPointOfTheSOnBounds.def(py::init<const gp_Pnt &, const Standard_Real, const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real>(), py::arg("P"), py::arg("Tol"), py::arg("A"), py::arg("Parameter"));
	cls_IntPatch_ThePathPointOfTheSOnBounds.def("SetValue", (void (IntPatch_ThePathPointOfTheSOnBounds::*)(const gp_Pnt &, const Standard_Real, const opencascade::handle<Adaptor3d_HVertex> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real)) &IntPatch_ThePathPointOfTheSOnBounds::SetValue, "None", py::arg("P"), py::arg("Tol"), py::arg("V"), py::arg("A"), py::arg("Parameter"));
	cls_IntPatch_ThePathPointOfTheSOnBounds.def("SetValue", (void (IntPatch_ThePathPointOfTheSOnBounds::*)(const gp_Pnt &, const Standard_Real, const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real)) &IntPatch_ThePathPointOfTheSOnBounds::SetValue, "None", py::arg("P"), py::arg("Tol"), py::arg("A"), py::arg("Parameter"));
	cls_IntPatch_ThePathPointOfTheSOnBounds.def("Value", (const gp_Pnt & (IntPatch_ThePathPointOfTheSOnBounds::*)() const ) &IntPatch_ThePathPointOfTheSOnBounds::Value, "None");
	cls_IntPatch_ThePathPointOfTheSOnBounds.def("Tolerance", (Standard_Real (IntPatch_ThePathPointOfTheSOnBounds::*)() const ) &IntPatch_ThePathPointOfTheSOnBounds::Tolerance, "None");
	cls_IntPatch_ThePathPointOfTheSOnBounds.def("IsNew", (Standard_Boolean (IntPatch_ThePathPointOfTheSOnBounds::*)() const ) &IntPatch_ThePathPointOfTheSOnBounds::IsNew, "None");
	cls_IntPatch_ThePathPointOfTheSOnBounds.def("Vertex", (const opencascade::handle<Adaptor3d_HVertex> & (IntPatch_ThePathPointOfTheSOnBounds::*)() const ) &IntPatch_ThePathPointOfTheSOnBounds::Vertex, "None");
	cls_IntPatch_ThePathPointOfTheSOnBounds.def("Arc", (const opencascade::handle<Adaptor2d_HCurve2d> & (IntPatch_ThePathPointOfTheSOnBounds::*)() const ) &IntPatch_ThePathPointOfTheSOnBounds::Arc, "None");
	cls_IntPatch_ThePathPointOfTheSOnBounds.def("Parameter", (Standard_Real (IntPatch_ThePathPointOfTheSOnBounds::*)() const ) &IntPatch_ThePathPointOfTheSOnBounds::Parameter, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_TheSegmentOfTheSOnBounds.hxx
	py::class_<IntPatch_TheSegmentOfTheSOnBounds, std::unique_ptr<IntPatch_TheSegmentOfTheSOnBounds, Deleter<IntPatch_TheSegmentOfTheSOnBounds>>> cls_IntPatch_TheSegmentOfTheSOnBounds(mod, "IntPatch_TheSegmentOfTheSOnBounds", "None");
	cls_IntPatch_TheSegmentOfTheSOnBounds.def(py::init<>());
	cls_IntPatch_TheSegmentOfTheSOnBounds.def("SetValue", (void (IntPatch_TheSegmentOfTheSOnBounds::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_TheSegmentOfTheSOnBounds::SetValue, "Defines the concerned arc.", py::arg("A"));
	cls_IntPatch_TheSegmentOfTheSOnBounds.def("SetLimitPoint", (void (IntPatch_TheSegmentOfTheSOnBounds::*)(const IntPatch_ThePathPointOfTheSOnBounds &, const Standard_Boolean)) &IntPatch_TheSegmentOfTheSOnBounds::SetLimitPoint, "Defines the first point or the last point, depending on the value of the boolean First.", py::arg("V"), py::arg("First"));
	cls_IntPatch_TheSegmentOfTheSOnBounds.def("Curve", (const opencascade::handle<Adaptor2d_HCurve2d> & (IntPatch_TheSegmentOfTheSOnBounds::*)() const ) &IntPatch_TheSegmentOfTheSOnBounds::Curve, "Returns the geometric curve on the surface 's domain which is solution.");
	cls_IntPatch_TheSegmentOfTheSOnBounds.def("HasFirstPoint", (Standard_Boolean (IntPatch_TheSegmentOfTheSOnBounds::*)() const ) &IntPatch_TheSegmentOfTheSOnBounds::HasFirstPoint, "Returns True if there is a vertex (ThePathPoint) defining the lowest valid parameter on the arc.");
	cls_IntPatch_TheSegmentOfTheSOnBounds.def("FirstPoint", (const IntPatch_ThePathPointOfTheSOnBounds & (IntPatch_TheSegmentOfTheSOnBounds::*)() const ) &IntPatch_TheSegmentOfTheSOnBounds::FirstPoint, "Returns the first point.");
	cls_IntPatch_TheSegmentOfTheSOnBounds.def("HasLastPoint", (Standard_Boolean (IntPatch_TheSegmentOfTheSOnBounds::*)() const ) &IntPatch_TheSegmentOfTheSOnBounds::HasLastPoint, "Returns True if there is a vertex (ThePathPoint) defining the greatest valid parameter on the arc.");
	cls_IntPatch_TheSegmentOfTheSOnBounds.def("LastPoint", (const IntPatch_ThePathPointOfTheSOnBounds & (IntPatch_TheSegmentOfTheSOnBounds::*)() const ) &IntPatch_TheSegmentOfTheSOnBounds::LastPoint, "Returns the last point.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_TheSOnBounds.hxx
	py::class_<IntPatch_TheSOnBounds, std::unique_ptr<IntPatch_TheSOnBounds, Deleter<IntPatch_TheSOnBounds>>> cls_IntPatch_TheSOnBounds(mod, "IntPatch_TheSOnBounds", "None");
	cls_IntPatch_TheSOnBounds.def(py::init<>());
	cls_IntPatch_TheSOnBounds.def("Perform", [](IntPatch_TheSOnBounds &self, IntPatch_ArcFunction & a0, const opencascade::handle<Adaptor3d_TopolTool> & a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Perform(a0, a1, a2, a3); }, py::arg("F"), py::arg("Domain"), py::arg("TolBoundary"), py::arg("TolTangency"));
	cls_IntPatch_TheSOnBounds.def("Perform", (void (IntPatch_TheSOnBounds::*)(IntPatch_ArcFunction &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &IntPatch_TheSOnBounds::Perform, "Algorithm to find the points and parts of curves of Domain (domain of of restriction of a surface) which verify F = 0. TolBoundary defines if a curve is on Q. TolTangency defines if a point is on Q.", py::arg("F"), py::arg("Domain"), py::arg("TolBoundary"), py::arg("TolTangency"), py::arg("RecheckOnRegularity"));
	cls_IntPatch_TheSOnBounds.def("IsDone", (Standard_Boolean (IntPatch_TheSOnBounds::*)() const ) &IntPatch_TheSOnBounds::IsDone, "Returns True if the calculus was successful.");
	cls_IntPatch_TheSOnBounds.def("AllArcSolution", (Standard_Boolean (IntPatch_TheSOnBounds::*)() const ) &IntPatch_TheSOnBounds::AllArcSolution, "Returns true if all arc of the Arcs are solution (inside the surface). An exception is raised if IsDone returns False.");
	cls_IntPatch_TheSOnBounds.def("NbPoints", (Standard_Integer (IntPatch_TheSOnBounds::*)() const ) &IntPatch_TheSOnBounds::NbPoints, "Returns the number of resulting points. An exception is raised if IsDone returns False (NotDone).");
	cls_IntPatch_TheSOnBounds.def("Point", (const IntPatch_ThePathPointOfTheSOnBounds & (IntPatch_TheSOnBounds::*)(const Standard_Integer) const ) &IntPatch_TheSOnBounds::Point, "Returns the resulting point of range Index. The exception NotDone is raised if IsDone() returns False. The exception OutOfRange is raised if Index <= 0 or Index > NbPoints.", py::arg("Index"));
	cls_IntPatch_TheSOnBounds.def("NbSegments", (Standard_Integer (IntPatch_TheSOnBounds::*)() const ) &IntPatch_TheSOnBounds::NbSegments, "Returns the number of the resulting segments. An exception is raised if IsDone returns False (NotDone).");
	cls_IntPatch_TheSOnBounds.def("Segment", (const IntPatch_TheSegmentOfTheSOnBounds & (IntPatch_TheSOnBounds::*)(const Standard_Integer) const ) &IntPatch_TheSOnBounds::Segment, "Returns the resulting segment of range Index. The exception NotDone is raised if IsDone() returns False. The exception OutOfRange is raised if Index <= 0 or Index > NbPoints.", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_ImpImpIntersection.hxx
	py::class_<IntPatch_ImpImpIntersection, std::unique_ptr<IntPatch_ImpImpIntersection, Deleter<IntPatch_ImpImpIntersection>>> cls_IntPatch_ImpImpIntersection(mod, "IntPatch_ImpImpIntersection", "Implementation of the intersection between two quadric patches : Plane, Cone, Cylinder or Sphere.");
	cls_IntPatch_ImpImpIntersection.def(py::init<>());
	cls_IntPatch_ImpImpIntersection.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real>(), py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"));
	cls_IntPatch_ImpImpIntersection.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"), py::arg("theIsReqToKeepRLine"));
	cls_IntPatch_ImpImpIntersection.def("Perform", [](IntPatch_ImpImpIntersection &self, const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_TopolTool> & a1, const opencascade::handle<Adaptor3d_HSurface> & a2, const opencascade::handle<Adaptor3d_TopolTool> & a3, const Standard_Real a4, const Standard_Real a5) -> void { return self.Perform(a0, a1, a2, a3, a4, a5); }, py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"));
	cls_IntPatch_ImpImpIntersection.def("Perform", (void (IntPatch_ImpImpIntersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &IntPatch_ImpImpIntersection::Perform, "Flag theIsReqToKeepRLine has been entered only for compatibility with TopOpeBRep package. It shall be deleted after deleting TopOpeBRep. When intersection result returns IntPatch_RLine and another IntPatch_Line (not restriction) we (in case of theIsReqToKeepRLine==TRUE) will always keep both lines even if they are coincided.", py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"), py::arg("theIsReqToKeepRLine"));
	cls_IntPatch_ImpImpIntersection.def("IsDone", (Standard_Boolean (IntPatch_ImpImpIntersection::*)() const ) &IntPatch_ImpImpIntersection::IsDone, "Returns True if the calculus was successful.");
	cls_IntPatch_ImpImpIntersection.def("GetStatus", (IntPatch_ImpImpIntersection::IntStatus (IntPatch_ImpImpIntersection::*)() const ) &IntPatch_ImpImpIntersection::GetStatus, "Returns status");
	cls_IntPatch_ImpImpIntersection.def("IsEmpty", (Standard_Boolean (IntPatch_ImpImpIntersection::*)() const ) &IntPatch_ImpImpIntersection::IsEmpty, "Returns true if the is no intersection.");
	cls_IntPatch_ImpImpIntersection.def("TangentFaces", (Standard_Boolean (IntPatch_ImpImpIntersection::*)() const ) &IntPatch_ImpImpIntersection::TangentFaces, "Returns True if the two patches are considered as entirely tangent, i.e every restriction arc of one patch is inside the geometric base of the other patch.");
	cls_IntPatch_ImpImpIntersection.def("OppositeFaces", (Standard_Boolean (IntPatch_ImpImpIntersection::*)() const ) &IntPatch_ImpImpIntersection::OppositeFaces, "Returns True when the TangentFaces returns True and the normal vectors evaluated at a point on the first and the second surface are opposite. The exception DomainError is raised if TangentFaces returns False.");
	cls_IntPatch_ImpImpIntersection.def("NbPnts", (Standard_Integer (IntPatch_ImpImpIntersection::*)() const ) &IntPatch_ImpImpIntersection::NbPnts, "Returns the number of 'single' points.");
	cls_IntPatch_ImpImpIntersection.def("Point", (const IntPatch_Point & (IntPatch_ImpImpIntersection::*)(const Standard_Integer) const ) &IntPatch_ImpImpIntersection::Point, "Returns the point of range Index. An exception is raised if Index<=0 or Index>NbPnt.", py::arg("Index"));
	cls_IntPatch_ImpImpIntersection.def("NbLines", (Standard_Integer (IntPatch_ImpImpIntersection::*)() const ) &IntPatch_ImpImpIntersection::NbLines, "Returns the number of intersection lines.");
	cls_IntPatch_ImpImpIntersection.def("Line", (const opencascade::handle<IntPatch_Line> & (IntPatch_ImpImpIntersection::*)(const Standard_Integer) const ) &IntPatch_ImpImpIntersection::Line, "Returns the line of range Index. An exception is raised if Index<=0 or Index>NbLine.", py::arg("Index"));
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_ImpImpIntersection.hxx
	py::enum_<IntPatch_ImpImpIntersection::IntStatus>(cls_IntPatch_ImpImpIntersection, "IntStatus", "None")
		.value("IntStatus_OK", IntPatch_ImpImpIntersection::IntStatus::IntStatus_OK)
		.value("IntStatus_InfiniteSectionCurve", IntPatch_ImpImpIntersection::IntStatus::IntStatus_InfiniteSectionCurve)
		.value("IntStatus_Fail", IntPatch_ImpImpIntersection::IntStatus::IntStatus_Fail)
		.export_values();

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_TheSurfFunction.hxx
	py::class_<IntPatch_TheSurfFunction, std::unique_ptr<IntPatch_TheSurfFunction, Deleter<IntPatch_TheSurfFunction>>, math_FunctionSetWithDerivatives> cls_IntPatch_TheSurfFunction(mod, "IntPatch_TheSurfFunction", "None");
	cls_IntPatch_TheSurfFunction.def(py::init<>());
	cls_IntPatch_TheSurfFunction.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const IntSurf_Quadric &>(), py::arg("PS"), py::arg("IS"));
	cls_IntPatch_TheSurfFunction.def(py::init<const IntSurf_Quadric &>(), py::arg("IS"));
	cls_IntPatch_TheSurfFunction.def("Set", (void (IntPatch_TheSurfFunction::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &IntPatch_TheSurfFunction::Set, "None", py::arg("PS"));
	cls_IntPatch_TheSurfFunction.def("SetImplicitSurface", (void (IntPatch_TheSurfFunction::*)(const IntSurf_Quadric &)) &IntPatch_TheSurfFunction::SetImplicitSurface, "None", py::arg("IS"));
	cls_IntPatch_TheSurfFunction.def("Set", (void (IntPatch_TheSurfFunction::*)(const Standard_Real)) &IntPatch_TheSurfFunction::Set, "None", py::arg("Tolerance"));
	cls_IntPatch_TheSurfFunction.def("NbVariables", (Standard_Integer (IntPatch_TheSurfFunction::*)() const ) &IntPatch_TheSurfFunction::NbVariables, "None");
	cls_IntPatch_TheSurfFunction.def("NbEquations", (Standard_Integer (IntPatch_TheSurfFunction::*)() const ) &IntPatch_TheSurfFunction::NbEquations, "None");
	cls_IntPatch_TheSurfFunction.def("Value", (Standard_Boolean (IntPatch_TheSurfFunction::*)(const math_Vector &, math_Vector &)) &IntPatch_TheSurfFunction::Value, "None", py::arg("X"), py::arg("F"));
	cls_IntPatch_TheSurfFunction.def("Derivatives", (Standard_Boolean (IntPatch_TheSurfFunction::*)(const math_Vector &, math_Matrix &)) &IntPatch_TheSurfFunction::Derivatives, "None", py::arg("X"), py::arg("D"));
	cls_IntPatch_TheSurfFunction.def("Values", (Standard_Boolean (IntPatch_TheSurfFunction::*)(const math_Vector &, math_Vector &, math_Matrix &)) &IntPatch_TheSurfFunction::Values, "None", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_IntPatch_TheSurfFunction.def("Root", (Standard_Real (IntPatch_TheSurfFunction::*)() const ) &IntPatch_TheSurfFunction::Root, "None");
	cls_IntPatch_TheSurfFunction.def("Tolerance", (Standard_Real (IntPatch_TheSurfFunction::*)() const ) &IntPatch_TheSurfFunction::Tolerance, "Returns the value Tol so that if Abs(Func.Root())<Tol the function is considered null.");
	cls_IntPatch_TheSurfFunction.def("Point", (const gp_Pnt & (IntPatch_TheSurfFunction::*)() const ) &IntPatch_TheSurfFunction::Point, "None");
	cls_IntPatch_TheSurfFunction.def("IsTangent", (Standard_Boolean (IntPatch_TheSurfFunction::*)()) &IntPatch_TheSurfFunction::IsTangent, "None");
	cls_IntPatch_TheSurfFunction.def("Direction3d", (const gp_Vec & (IntPatch_TheSurfFunction::*)()) &IntPatch_TheSurfFunction::Direction3d, "None");
	cls_IntPatch_TheSurfFunction.def("Direction2d", (const gp_Dir2d & (IntPatch_TheSurfFunction::*)()) &IntPatch_TheSurfFunction::Direction2d, "None");
	cls_IntPatch_TheSurfFunction.def("PSurface", (const opencascade::handle<Adaptor3d_HSurface> & (IntPatch_TheSurfFunction::*)() const ) &IntPatch_TheSurfFunction::PSurface, "None");
	cls_IntPatch_TheSurfFunction.def("ISurface", (const IntSurf_Quadric & (IntPatch_TheSurfFunction::*)() const ) &IntPatch_TheSurfFunction::ISurface, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_TheSearchInside.hxx
	py::class_<IntPatch_TheSearchInside, std::unique_ptr<IntPatch_TheSearchInside, Deleter<IntPatch_TheSearchInside>>> cls_IntPatch_TheSearchInside(mod, "IntPatch_TheSearchInside", "None");
	cls_IntPatch_TheSearchInside.def(py::init<>());
	cls_IntPatch_TheSearchInside.def(py::init<IntPatch_TheSurfFunction &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real>(), py::arg("F"), py::arg("Surf"), py::arg("T"), py::arg("Epsilon"));
	cls_IntPatch_TheSearchInside.def("Perform", (void (IntPatch_TheSearchInside::*)(IntPatch_TheSurfFunction &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real)) &IntPatch_TheSearchInside::Perform, "None", py::arg("F"), py::arg("Surf"), py::arg("T"), py::arg("Epsilon"));
	cls_IntPatch_TheSearchInside.def("Perform", (void (IntPatch_TheSearchInside::*)(IntPatch_TheSurfFunction &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real)) &IntPatch_TheSearchInside::Perform, "None", py::arg("F"), py::arg("Surf"), py::arg("UStart"), py::arg("VStart"));
	cls_IntPatch_TheSearchInside.def("IsDone", (Standard_Boolean (IntPatch_TheSearchInside::*)() const ) &IntPatch_TheSearchInside::IsDone, "None");
	cls_IntPatch_TheSearchInside.def("NbPoints", (Standard_Integer (IntPatch_TheSearchInside::*)() const ) &IntPatch_TheSearchInside::NbPoints, "Returns the number of points. The exception NotDone if raised if IsDone returns False.");
	cls_IntPatch_TheSearchInside.def("Value", (const IntSurf_InteriorPoint & (IntPatch_TheSearchInside::*)(const Standard_Integer) const ) &IntPatch_TheSearchInside::Value, "Returns the point of range Index. The exception NotDone if raised if IsDone returns False. The exception OutOfRange if raised if Index <= 0 or Index > NbPoints.", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_ImpPrmIntersection.hxx
	py::class_<IntPatch_ImpPrmIntersection, std::unique_ptr<IntPatch_ImpPrmIntersection, Deleter<IntPatch_ImpPrmIntersection>>> cls_IntPatch_ImpPrmIntersection(mod, "IntPatch_ImpPrmIntersection", "Implementation of the intersection between a natural quadric patch : Plane, Cone, Cylinder or Sphere and a bi-parametrised surface.");
	cls_IntPatch_ImpPrmIntersection.def(py::init<>());
	cls_IntPatch_ImpPrmIntersection.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Surf1"), py::arg("D1"), py::arg("Surf2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"), py::arg("Fleche"), py::arg("Pas"));
	cls_IntPatch_ImpPrmIntersection.def("SetStartPoint", (void (IntPatch_ImpPrmIntersection::*)(const Standard_Real, const Standard_Real)) &IntPatch_ImpPrmIntersection::SetStartPoint, "to search for solution from the given point", py::arg("U"), py::arg("V"));
	cls_IntPatch_ImpPrmIntersection.def("Perform", (void (IntPatch_ImpPrmIntersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_ImpPrmIntersection::Perform, "None", py::arg("Surf1"), py::arg("D1"), py::arg("Surf2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"), py::arg("Fleche"), py::arg("Pas"));
	cls_IntPatch_ImpPrmIntersection.def("IsDone", (Standard_Boolean (IntPatch_ImpPrmIntersection::*)() const ) &IntPatch_ImpPrmIntersection::IsDone, "Returns true if the calculus was succesfull.");
	cls_IntPatch_ImpPrmIntersection.def("IsEmpty", (Standard_Boolean (IntPatch_ImpPrmIntersection::*)() const ) &IntPatch_ImpPrmIntersection::IsEmpty, "Returns true if the is no intersection.");
	cls_IntPatch_ImpPrmIntersection.def("NbPnts", (Standard_Integer (IntPatch_ImpPrmIntersection::*)() const ) &IntPatch_ImpPrmIntersection::NbPnts, "Returns the number of 'single' points.");
	cls_IntPatch_ImpPrmIntersection.def("Point", (const IntPatch_Point & (IntPatch_ImpPrmIntersection::*)(const Standard_Integer) const ) &IntPatch_ImpPrmIntersection::Point, "Returns the point of range Index. An exception is raised if Index<=0 or Index>NbPnt.", py::arg("Index"));
	cls_IntPatch_ImpPrmIntersection.def("NbLines", (Standard_Integer (IntPatch_ImpPrmIntersection::*)() const ) &IntPatch_ImpPrmIntersection::NbLines, "Returns the number of intersection lines.");
	cls_IntPatch_ImpPrmIntersection.def("Line", (const opencascade::handle<IntPatch_Line> & (IntPatch_ImpPrmIntersection::*)(const Standard_Integer) const ) &IntPatch_ImpPrmIntersection::Line, "Returns the line of range Index. An exception is raised if Index<=0 or Index>NbLine.", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_Polyhedron.hxx
	py::class_<IntPatch_Polyhedron, std::unique_ptr<IntPatch_Polyhedron, Deleter<IntPatch_Polyhedron>>> cls_IntPatch_Polyhedron(mod, "IntPatch_Polyhedron", "This class provides a linear approximation of the PSurface. preview a constructor on a zone of a surface");
	cls_IntPatch_Polyhedron.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Integer>(), py::arg("Surface"), py::arg("nbdU"), py::arg("nbdV"));
	cls_IntPatch_Polyhedron.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("Surface"));
	cls_IntPatch_Polyhedron.def("Destroy", (void (IntPatch_Polyhedron::*)()) &IntPatch_Polyhedron::Destroy, "None");
	cls_IntPatch_Polyhedron.def("Perform", (void (IntPatch_Polyhedron::*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Integer)) &IntPatch_Polyhedron::Perform, "None", py::arg("Surface"), py::arg("nbdU"), py::arg("nbdV"));
	cls_IntPatch_Polyhedron.def("DeflectionOverEstimation", (void (IntPatch_Polyhedron::*)(const Standard_Real)) &IntPatch_Polyhedron::DeflectionOverEstimation, "None", py::arg("flec"));
	cls_IntPatch_Polyhedron.def("DeflectionOnTriangle", (Standard_Real (IntPatch_Polyhedron::*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer) const ) &IntPatch_Polyhedron::DeflectionOnTriangle, "None", py::arg("Surface"), py::arg("Index"));
	cls_IntPatch_Polyhedron.def("UMinSingularity", (void (IntPatch_Polyhedron::*)(const Standard_Boolean)) &IntPatch_Polyhedron::UMinSingularity, "None", py::arg("Sing"));
	cls_IntPatch_Polyhedron.def("UMaxSingularity", (void (IntPatch_Polyhedron::*)(const Standard_Boolean)) &IntPatch_Polyhedron::UMaxSingularity, "None", py::arg("Sing"));
	cls_IntPatch_Polyhedron.def("VMinSingularity", (void (IntPatch_Polyhedron::*)(const Standard_Boolean)) &IntPatch_Polyhedron::VMinSingularity, "None", py::arg("Sing"));
	cls_IntPatch_Polyhedron.def("VMaxSingularity", (void (IntPatch_Polyhedron::*)(const Standard_Boolean)) &IntPatch_Polyhedron::VMaxSingularity, "None", py::arg("Sing"));
	cls_IntPatch_Polyhedron.def("Size", (void (IntPatch_Polyhedron::*)(Standard_Integer &, Standard_Integer &) const ) &IntPatch_Polyhedron::Size, "Get the size of the MaTriangle.", py::arg("nbdu"), py::arg("nbdv"));
	cls_IntPatch_Polyhedron.def("NbTriangles", (Standard_Integer (IntPatch_Polyhedron::*)() const ) &IntPatch_Polyhedron::NbTriangles, "Give the number of triangles in this double array of triangles (nbdu*nbdv*2).");
	cls_IntPatch_Polyhedron.def("Triangle", (void (IntPatch_Polyhedron::*)(const Standard_Integer, Standard_Integer &, Standard_Integer &, Standard_Integer &) const ) &IntPatch_Polyhedron::Triangle, "Give the 3 points of the triangle of addresse Index in the double array of triangles.", py::arg("Index"), py::arg("P1"), py::arg("P2"), py::arg("P3"));
	cls_IntPatch_Polyhedron.def("TriConnex", (Standard_Integer (IntPatch_Polyhedron::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, Standard_Integer &, Standard_Integer &) const ) &IntPatch_Polyhedron::TriConnex, "Give the addresse Tricon of the triangle connexe to the triangle of address Triang by the edge Pivot Pedge and the third point of this connexe triangle. When we are on a free edge TriCon==0 but the function return the value of the triangle in the other side of Pivot on the free edge. Used to turn around a vertex.", py::arg("Triang"), py::arg("Pivot"), py::arg("Pedge"), py::arg("TriCon"), py::arg("OtherP"));
	cls_IntPatch_Polyhedron.def("NbPoints", (Standard_Integer (IntPatch_Polyhedron::*)() const ) &IntPatch_Polyhedron::NbPoints, "Give the number of point in the double array of triangles ((nbdu+1)*(nbdv+1)).");
	cls_IntPatch_Polyhedron.def("Point", (void (IntPatch_Polyhedron::*)(const gp_Pnt &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real)) &IntPatch_Polyhedron::Point, "Set the value of a field of the double array of points.", py::arg("thePnt"), py::arg("lig"), py::arg("col"), py::arg("U"), py::arg("V"));
	cls_IntPatch_Polyhedron.def("Point", (const gp_Pnt & (IntPatch_Polyhedron::*)(const Standard_Integer, Standard_Real &, Standard_Real &) const ) &IntPatch_Polyhedron::Point, "Give the point of index i in the MaTriangle.", py::arg("Index"), py::arg("U"), py::arg("V"));
	cls_IntPatch_Polyhedron.def("Point", (const gp_Pnt & (IntPatch_Polyhedron::*)(const Standard_Integer) const ) &IntPatch_Polyhedron::Point, "Give the point of index i in the MaTriangle.", py::arg("Index"));
	cls_IntPatch_Polyhedron.def("Point", (void (IntPatch_Polyhedron::*)(const Standard_Integer, gp_Pnt &) const ) &IntPatch_Polyhedron::Point, "Give the point of index i in the MaTriangle.", py::arg("Index"), py::arg("P"));
	cls_IntPatch_Polyhedron.def("Bounding", (const Bnd_Box & (IntPatch_Polyhedron::*)() const ) &IntPatch_Polyhedron::Bounding, "Give the bounding box of the MaTriangle.");
	cls_IntPatch_Polyhedron.def("FillBounding", (void (IntPatch_Polyhedron::*)()) &IntPatch_Polyhedron::FillBounding, "Compute the array of boxes. The box <n> corresponding to the triangle <n>.");
	cls_IntPatch_Polyhedron.def("ComponentsBounding", (const opencascade::handle<Bnd_HArray1OfBox> & (IntPatch_Polyhedron::*)() const ) &IntPatch_Polyhedron::ComponentsBounding, "Give the array of boxes. The box <n> corresponding to the triangle <n>.");
	cls_IntPatch_Polyhedron.def("DeflectionOverEstimation", (Standard_Real (IntPatch_Polyhedron::*)() const ) &IntPatch_Polyhedron::DeflectionOverEstimation, "None");
	cls_IntPatch_Polyhedron.def("HasUMinSingularity", (Standard_Boolean (IntPatch_Polyhedron::*)() const ) &IntPatch_Polyhedron::HasUMinSingularity, "None");
	cls_IntPatch_Polyhedron.def("HasUMaxSingularity", (Standard_Boolean (IntPatch_Polyhedron::*)() const ) &IntPatch_Polyhedron::HasUMaxSingularity, "None");
	cls_IntPatch_Polyhedron.def("HasVMinSingularity", (Standard_Boolean (IntPatch_Polyhedron::*)() const ) &IntPatch_Polyhedron::HasVMinSingularity, "None");
	cls_IntPatch_Polyhedron.def("HasVMaxSingularity", (Standard_Boolean (IntPatch_Polyhedron::*)() const ) &IntPatch_Polyhedron::HasVMaxSingularity, "None");
	cls_IntPatch_Polyhedron.def("PlaneEquation", (void (IntPatch_Polyhedron::*)(const Standard_Integer, gp_XYZ &, Standard_Real &) const ) &IntPatch_Polyhedron::PlaneEquation, "Give the plane equation of the triangle of addresse Triang.", py::arg("Triang"), py::arg("NormalVector"), py::arg("PolarDistance"));
	cls_IntPatch_Polyhedron.def("Contain", (Standard_Boolean (IntPatch_Polyhedron::*)(const Standard_Integer, const gp_Pnt &) const ) &IntPatch_Polyhedron::Contain, "Give the plane equation of the triangle of addresse Triang.", py::arg("Triang"), py::arg("ThePnt"));
	cls_IntPatch_Polyhedron.def("Parameters", (void (IntPatch_Polyhedron::*)(const Standard_Integer, Standard_Real &, Standard_Real &) const ) &IntPatch_Polyhedron::Parameters, "None", py::arg("Index"), py::arg("U"), py::arg("V"));
	// FIXME cls_IntPatch_Polyhedron.def("Dump", (void (IntPatch_Polyhedron::*)() const ) &IntPatch_Polyhedron::Dump, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_InterferencePolyhedron.hxx
	py::class_<IntPatch_InterferencePolyhedron, std::unique_ptr<IntPatch_InterferencePolyhedron, Deleter<IntPatch_InterferencePolyhedron>>, Intf_Interference> cls_IntPatch_InterferencePolyhedron(mod, "IntPatch_InterferencePolyhedron", "Computes the interference between two polyhedra or the self interference of a polyhedron. Points of intersection, polylines of intersection and zones of tangence.");
	cls_IntPatch_InterferencePolyhedron.def(py::init<>());
	cls_IntPatch_InterferencePolyhedron.def(py::init<const IntPatch_Polyhedron &, const IntPatch_Polyhedron &>(), py::arg("Obje1"), py::arg("Obje2"));
	cls_IntPatch_InterferencePolyhedron.def(py::init<const IntPatch_Polyhedron &>(), py::arg("Obje"));
	cls_IntPatch_InterferencePolyhedron.def("Perform", (void (IntPatch_InterferencePolyhedron::*)(const IntPatch_Polyhedron &, const IntPatch_Polyhedron &)) &IntPatch_InterferencePolyhedron::Perform, "Computes the interference between the two Polyhedra.", py::arg("Obje1"), py::arg("Obje2"));
	cls_IntPatch_InterferencePolyhedron.def("Perform", (void (IntPatch_InterferencePolyhedron::*)(const IntPatch_Polyhedron &)) &IntPatch_InterferencePolyhedron::Perform, "Computes the self interference of a Polyhedron.", py::arg("Obje"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_LineConstructor.hxx
	py::class_<IntPatch_LineConstructor, std::unique_ptr<IntPatch_LineConstructor, Deleter<IntPatch_LineConstructor>>> cls_IntPatch_LineConstructor(mod, "IntPatch_LineConstructor", "The intersections algorithms compute the intersection on two surfaces and return the intersections lines as IntPatch_Line.");
	cls_IntPatch_LineConstructor.def(py::init<const Standard_Integer>(), py::arg("mode"));
	cls_IntPatch_LineConstructor.def("Perform", (void (IntPatch_LineConstructor::*)(const IntPatch_SequenceOfLine &, const opencascade::handle<IntPatch_Line> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real)) &IntPatch_LineConstructor::Perform, "None", py::arg("SL"), py::arg("L"), py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("Tol"));
	cls_IntPatch_LineConstructor.def("NbLines", (Standard_Integer (IntPatch_LineConstructor::*)() const ) &IntPatch_LineConstructor::NbLines, "None");
	cls_IntPatch_LineConstructor.def("Line", (opencascade::handle<IntPatch_Line> (IntPatch_LineConstructor::*)(const Standard_Integer) const ) &IntPatch_LineConstructor::Line, "None", py::arg("index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_RLine.hxx
	py::class_<IntPatch_RLine, opencascade::handle<IntPatch_RLine>, IntPatch_PointLine> cls_IntPatch_RLine(mod, "IntPatch_RLine", "Implementation of an intersection line described by a restriction line on one of the surfaces.");
	cls_IntPatch_RLine.def(py::init<const Standard_Boolean, const IntSurf_TypeTrans, const IntSurf_TypeTrans>(), py::arg("Tang"), py::arg("Trans1"), py::arg("Trans2"));
	cls_IntPatch_RLine.def(py::init<const Standard_Boolean, const IntSurf_Situation, const IntSurf_Situation>(), py::arg("Tang"), py::arg("Situ1"), py::arg("Situ2"));
	cls_IntPatch_RLine.def(py::init<const Standard_Boolean>(), py::arg("Tang"));
	cls_IntPatch_RLine.def("AddVertex", [](IntPatch_RLine &self, const IntPatch_Point & a0) -> void { return self.AddVertex(a0); }, py::arg("Pnt"));
	cls_IntPatch_RLine.def("AddVertex", (void (IntPatch_RLine::*)(const IntPatch_Point &, const Standard_Boolean)) &IntPatch_RLine::AddVertex, "Adds a vertex in the list. If theIsPrepend == TRUE the new vertex will be added before the first element of vertices sequence. Otherwise, to the end of the sequence", py::arg("Pnt"), py::arg("theIsPrepend"));
	cls_IntPatch_RLine.def("Replace", (void (IntPatch_RLine::*)(const Standard_Integer, const IntPatch_Point &)) &IntPatch_RLine::Replace, "Replaces the element of range Index in the list of points.", py::arg("Index"), py::arg("Pnt"));
	cls_IntPatch_RLine.def("SetFirstPoint", (void (IntPatch_RLine::*)(const Standard_Integer)) &IntPatch_RLine::SetFirstPoint, "None", py::arg("IndFirst"));
	cls_IntPatch_RLine.def("SetLastPoint", (void (IntPatch_RLine::*)(const Standard_Integer)) &IntPatch_RLine::SetLastPoint, "None", py::arg("IndLast"));
	cls_IntPatch_RLine.def("Add", (void (IntPatch_RLine::*)(const opencascade::handle<IntSurf_LineOn2S> &)) &IntPatch_RLine::Add, "None", py::arg("L"));
	cls_IntPatch_RLine.def("IsArcOnS1", (Standard_Boolean (IntPatch_RLine::*)() const ) &IntPatch_RLine::IsArcOnS1, "Returns True if the intersection is on the domain of the first patch. Returns False if the intersection is on the domain of the second patch.");
	cls_IntPatch_RLine.def("IsArcOnS2", (Standard_Boolean (IntPatch_RLine::*)() const ) &IntPatch_RLine::IsArcOnS2, "Returns True if the intersection is on the domain of the first patch. Returns False if the intersection is on the domain of the second patch.");
	cls_IntPatch_RLine.def("SetArcOnS1", (void (IntPatch_RLine::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_RLine::SetArcOnS1, "None", py::arg("A"));
	cls_IntPatch_RLine.def("SetArcOnS2", (void (IntPatch_RLine::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_RLine::SetArcOnS2, "None", py::arg("A"));
	cls_IntPatch_RLine.def("SetParamOnS1", (void (IntPatch_RLine::*)(const Standard_Real, const Standard_Real)) &IntPatch_RLine::SetParamOnS1, "None", py::arg("p1"), py::arg("p2"));
	cls_IntPatch_RLine.def("SetParamOnS2", (void (IntPatch_RLine::*)(Standard_Real &, Standard_Real &)) &IntPatch_RLine::SetParamOnS2, "None", py::arg("p1"), py::arg("p2"));
	cls_IntPatch_RLine.def("ArcOnS1", (const opencascade::handle<Adaptor2d_HCurve2d> & (IntPatch_RLine::*)() const ) &IntPatch_RLine::ArcOnS1, "Returns the concerned arc.");
	cls_IntPatch_RLine.def("ArcOnS2", (const opencascade::handle<Adaptor2d_HCurve2d> & (IntPatch_RLine::*)() const ) &IntPatch_RLine::ArcOnS2, "Returns the concerned arc.");
	cls_IntPatch_RLine.def("ParamOnS1", (void (IntPatch_RLine::*)(Standard_Real &, Standard_Real &) const ) &IntPatch_RLine::ParamOnS1, "None", py::arg("p1"), py::arg("p2"));
	cls_IntPatch_RLine.def("ParamOnS2", (void (IntPatch_RLine::*)(Standard_Real &, Standard_Real &) const ) &IntPatch_RLine::ParamOnS2, "None", py::arg("p1"), py::arg("p2"));
	cls_IntPatch_RLine.def("HasFirstPoint", (Standard_Boolean (IntPatch_RLine::*)() const ) &IntPatch_RLine::HasFirstPoint, "Returns True if the line has a known First point. This point is given by the method FirstPoint().");
	cls_IntPatch_RLine.def("HasLastPoint", (Standard_Boolean (IntPatch_RLine::*)() const ) &IntPatch_RLine::HasLastPoint, "Returns True if the line has a known Last point. This point is given by the method LastPoint().");
	cls_IntPatch_RLine.def("FirstPoint", (const IntPatch_Point & (IntPatch_RLine::*)() const ) &IntPatch_RLine::FirstPoint, "Returns the IntPoint corresponding to the FirstPoint. An exception is raised when HasFirstPoint returns False.");
	cls_IntPatch_RLine.def("LastPoint", (const IntPatch_Point & (IntPatch_RLine::*)() const ) &IntPatch_RLine::LastPoint, "Returns the IntPoint corresponding to the LastPoint. An exception is raised when HasLastPoint returns False.");
	cls_IntPatch_RLine.def("NbVertex", (Standard_Integer (IntPatch_RLine::*)() const ) &IntPatch_RLine::NbVertex, "Returns number of vertices (IntPatch_Point) of the line");
	cls_IntPatch_RLine.def("Vertex", (const IntPatch_Point & (IntPatch_RLine::*)(const Standard_Integer) const ) &IntPatch_RLine::Vertex, "Returns the vertex of range Index on the line.", py::arg("Index"));
	cls_IntPatch_RLine.def("ChangeVertex", (IntPatch_Point & (IntPatch_RLine::*)(const Standard_Integer)) &IntPatch_RLine::ChangeVertex, "Returns the vertex of range Index on the line.", py::arg("Index"));
	cls_IntPatch_RLine.def("RemoveVertex", (void (IntPatch_RLine::*)(const Standard_Integer)) &IntPatch_RLine::RemoveVertex, "Removes single vertex from the line", py::arg("theIndex"));
	cls_IntPatch_RLine.def("HasPolygon", (Standard_Boolean (IntPatch_RLine::*)() const ) &IntPatch_RLine::HasPolygon, "None");
	cls_IntPatch_RLine.def("NbPnts", (Standard_Integer (IntPatch_RLine::*)() const ) &IntPatch_RLine::NbPnts, "Returns the number of intersection points.");
	cls_IntPatch_RLine.def("Point", (const IntSurf_PntOn2S & (IntPatch_RLine::*)(const Standard_Integer) const ) &IntPatch_RLine::Point, "Returns the intersection point of range Index.", py::arg("Index"));
	cls_IntPatch_RLine.def("SetPoint", (void (IntPatch_RLine::*)(const Standard_Integer, const IntPatch_Point &)) &IntPatch_RLine::SetPoint, "Set the Point of index <Index> in the LineOn2S", py::arg("Index"), py::arg("Pnt"));
	cls_IntPatch_RLine.def("ComputeVertexParameters", (void (IntPatch_RLine::*)(const Standard_Real)) &IntPatch_RLine::ComputeVertexParameters, "Set the parameters of all the vertex on the line. if a vertex is already in the line, its parameter is modified else a new point in the line is inserted.", py::arg("Tol"));
	cls_IntPatch_RLine.def("Curve", (opencascade::handle<IntSurf_LineOn2S> (IntPatch_RLine::*)() const ) &IntPatch_RLine::Curve, "Returns set of intersection points");
	cls_IntPatch_RLine.def("ClearVertexes", (void (IntPatch_RLine::*)()) &IntPatch_RLine::ClearVertexes, "Removes vertices from the line (i.e. cleans svtx member)");
	cls_IntPatch_RLine.def("SetCurve", (void (IntPatch_RLine::*)(const opencascade::handle<IntSurf_LineOn2S> &)) &IntPatch_RLine::SetCurve, "None", py::arg("theNewCurve"));
	// FIXME cls_IntPatch_RLine.def("Dump", (void (IntPatch_RLine::*)(const Standard_Integer) const ) &IntPatch_RLine::Dump, "if (theMode == 0) then prints the information about WLine if (theMode == 1) then prints the list of 3d-points if (theMode == 2) then prints the list of 2d-points on the 1st surface Otherwise, prints list of 2d-points on the 2nd surface", py::arg("theMode"));
	cls_IntPatch_RLine.def_static("get_type_name_", (const char * (*)()) &IntPatch_RLine::get_type_name, "None");
	cls_IntPatch_RLine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntPatch_RLine::get_type_descriptor, "None");
	cls_IntPatch_RLine.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntPatch_RLine::*)() const ) &IntPatch_RLine::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_Polygo.hxx
	py::class_<IntPatch_Polygo, std::unique_ptr<IntPatch_Polygo, Deleter<IntPatch_Polygo>>, Intf_Polygon2d> cls_IntPatch_Polygo(mod, "IntPatch_Polygo", "None");
	cls_IntPatch_Polygo.def("Error", (Standard_Real (IntPatch_Polygo::*)() const ) &IntPatch_Polygo::Error, "None");
	cls_IntPatch_Polygo.def("NbPoints", (Standard_Integer (IntPatch_Polygo::*)() const ) &IntPatch_Polygo::NbPoints, "None");
	cls_IntPatch_Polygo.def("Point", (gp_Pnt2d (IntPatch_Polygo::*)(const Standard_Integer) const ) &IntPatch_Polygo::Point, "None", py::arg("Index"));
	cls_IntPatch_Polygo.def("DeflectionOverEstimation", (Standard_Real (IntPatch_Polygo::*)() const ) &IntPatch_Polygo::DeflectionOverEstimation, "Returns the tolerance of the polygon.");
	cls_IntPatch_Polygo.def("NbSegments", (Standard_Integer (IntPatch_Polygo::*)() const ) &IntPatch_Polygo::NbSegments, "Returns the number of Segments in the polyline.");
	cls_IntPatch_Polygo.def("Segment", (void (IntPatch_Polygo::*)(const Standard_Integer, gp_Pnt2d &, gp_Pnt2d &) const ) &IntPatch_Polygo::Segment, "Returns the points of the segment <Index> in the Polygon.", py::arg("theIndex"), py::arg("theBegin"), py::arg("theEnd"));
	// FIXME cls_IntPatch_Polygo.def("Dump", (void (IntPatch_Polygo::*)() const ) &IntPatch_Polygo::Dump, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_PolyArc.hxx
	py::class_<IntPatch_PolyArc, std::unique_ptr<IntPatch_PolyArc, Deleter<IntPatch_PolyArc>>, IntPatch_Polygo> cls_IntPatch_PolyArc(mod, "IntPatch_PolyArc", "None");
	cls_IntPatch_PolyArc.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Integer, const Standard_Real, const Standard_Real, const Bnd_Box2d &>(), py::arg("A"), py::arg("NbSample"), py::arg("Pfirst"), py::arg("Plast"), py::arg("BoxOtherPolygon"));
	cls_IntPatch_PolyArc.def("Closed", (Standard_Boolean (IntPatch_PolyArc::*)() const ) &IntPatch_PolyArc::Closed, "None");
	cls_IntPatch_PolyArc.def("NbPoints", (Standard_Integer (IntPatch_PolyArc::*)() const ) &IntPatch_PolyArc::NbPoints, "None");
	cls_IntPatch_PolyArc.def("Point", (gp_Pnt2d (IntPatch_PolyArc::*)(const Standard_Integer) const ) &IntPatch_PolyArc::Point, "None", py::arg("Index"));
	cls_IntPatch_PolyArc.def("Parameter", (Standard_Real (IntPatch_PolyArc::*)(const Standard_Integer) const ) &IntPatch_PolyArc::Parameter, "None", py::arg("Index"));
	cls_IntPatch_PolyArc.def("SetOffset", (void (IntPatch_PolyArc::*)(const Standard_Real, const Standard_Real)) &IntPatch_PolyArc::SetOffset, "None", py::arg("OffsetX"), py::arg("OffsetY"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_PolyhedronTool.hxx
	py::class_<IntPatch_PolyhedronTool, std::unique_ptr<IntPatch_PolyhedronTool, Deleter<IntPatch_PolyhedronTool>>> cls_IntPatch_PolyhedronTool(mod, "IntPatch_PolyhedronTool", "Describe the signature of a polyedral surface with only triangular facets and the necessary informations to compute the interferences.");
	cls_IntPatch_PolyhedronTool.def(py::init<>());
	cls_IntPatch_PolyhedronTool.def_static("Bounding_", (const Bnd_Box & (*)(const IntPatch_Polyhedron &)) &IntPatch_PolyhedronTool::Bounding, "Give the bounding box of the Polyhedron.", py::arg("thePolyh"));
	cls_IntPatch_PolyhedronTool.def_static("ComponentsBounding_", (const opencascade::handle<Bnd_HArray1OfBox> & (*)(const IntPatch_Polyhedron &)) &IntPatch_PolyhedronTool::ComponentsBounding, "Give the array of boxes. The box <n> corresponding to the triangle <n>.", py::arg("thePolyh"));
	cls_IntPatch_PolyhedronTool.def_static("DeflectionOverEstimation_", (Standard_Real (*)(const IntPatch_Polyhedron &)) &IntPatch_PolyhedronTool::DeflectionOverEstimation, "Give the tolerance of the polygon.", py::arg("thePolyh"));
	cls_IntPatch_PolyhedronTool.def_static("NbTriangles_", (Standard_Integer (*)(const IntPatch_Polyhedron &)) &IntPatch_PolyhedronTool::NbTriangles, "Give the number of triangles in this polyedral surface.", py::arg("thePolyh"));
	cls_IntPatch_PolyhedronTool.def_static("Triangle_", (void (*)(const IntPatch_Polyhedron &, const Standard_Integer, Standard_Integer &, Standard_Integer &, Standard_Integer &)) &IntPatch_PolyhedronTool::Triangle, "Give the indices of the 3 points of the triangle of address Index in the Polyhedron.", py::arg("thePolyh"), py::arg("Index"), py::arg("P1"), py::arg("P2"), py::arg("P3"));
	cls_IntPatch_PolyhedronTool.def_static("Point_", (const gp_Pnt & (*)(const IntPatch_Polyhedron &, const Standard_Integer)) &IntPatch_PolyhedronTool::Point, "Give the point of index i in the polyedral surface.", py::arg("thePolyh"), py::arg("Index"));
	cls_IntPatch_PolyhedronTool.def_static("TriConnex_", (Standard_Integer (*)(const IntPatch_Polyhedron &, const Standard_Integer, const Standard_Integer, const Standard_Integer, Standard_Integer &, Standard_Integer &)) &IntPatch_PolyhedronTool::TriConnex, "Gives the addresse Tricon of the triangle connexe to the triangle of address Triang by the edge Pivot Pedge and the third point of this connexe triangle. When we are on a free edge TriCon==0 but the function return the value of the triangle in the other side of Pivot on the free edge. Used to turn around a vertex.", py::arg("thePolyh"), py::arg("Triang"), py::arg("Pivot"), py::arg("Pedge"), py::arg("TriCon"), py::arg("OtherP"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_PolyLine.hxx
	py::class_<IntPatch_PolyLine, std::unique_ptr<IntPatch_PolyLine, Deleter<IntPatch_PolyLine>>, IntPatch_Polygo> cls_IntPatch_PolyLine(mod, "IntPatch_PolyLine", "None");
	cls_IntPatch_PolyLine.def(py::init<>());
	cls_IntPatch_PolyLine.def(py::init<const Standard_Real>(), py::arg("InitDefle"));
	cls_IntPatch_PolyLine.def("SetWLine", (void (IntPatch_PolyLine::*)(const Standard_Boolean, const opencascade::handle<IntPatch_WLine> &)) &IntPatch_PolyLine::SetWLine, "None", py::arg("OnFirst"), py::arg("Line"));
	cls_IntPatch_PolyLine.def("SetRLine", (void (IntPatch_PolyLine::*)(const Standard_Boolean, const opencascade::handle<IntPatch_RLine> &)) &IntPatch_PolyLine::SetRLine, "None", py::arg("OnFirst"), py::arg("Line"));
	cls_IntPatch_PolyLine.def("ResetError", (void (IntPatch_PolyLine::*)()) &IntPatch_PolyLine::ResetError, "None");
	cls_IntPatch_PolyLine.def("NbPoints", (Standard_Integer (IntPatch_PolyLine::*)() const ) &IntPatch_PolyLine::NbPoints, "None");
	cls_IntPatch_PolyLine.def("Point", (gp_Pnt2d (IntPatch_PolyLine::*)(const Standard_Integer) const ) &IntPatch_PolyLine::Point, "None", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_PrmPrmIntersection_T3Bits.hxx
	py::class_<IntPatch_PrmPrmIntersection_T3Bits, std::unique_ptr<IntPatch_PrmPrmIntersection_T3Bits, Deleter<IntPatch_PrmPrmIntersection_T3Bits>>> cls_IntPatch_PrmPrmIntersection_T3Bits(mod, "IntPatch_PrmPrmIntersection_T3Bits", "None");
	cls_IntPatch_PrmPrmIntersection_T3Bits.def(py::init<const Standard_Integer>(), py::arg("size"));
	cls_IntPatch_PrmPrmIntersection_T3Bits.def("Destroy", (void (IntPatch_PrmPrmIntersection_T3Bits::*)()) &IntPatch_PrmPrmIntersection_T3Bits::Destroy, "None");
	cls_IntPatch_PrmPrmIntersection_T3Bits.def("Add", (void (IntPatch_PrmPrmIntersection_T3Bits::*)(const Standard_Integer)) &IntPatch_PrmPrmIntersection_T3Bits::Add, "None", py::arg("t"));
	cls_IntPatch_PrmPrmIntersection_T3Bits.def("Val", (Standard_Integer (IntPatch_PrmPrmIntersection_T3Bits::*)(const Standard_Integer) const ) &IntPatch_PrmPrmIntersection_T3Bits::Val, "None", py::arg("t"));
	cls_IntPatch_PrmPrmIntersection_T3Bits.def("Raz", (void (IntPatch_PrmPrmIntersection_T3Bits::*)(const Standard_Integer)) &IntPatch_PrmPrmIntersection_T3Bits::Raz, "None", py::arg("t"));
	cls_IntPatch_PrmPrmIntersection_T3Bits.def("ResetAnd", (void (IntPatch_PrmPrmIntersection_T3Bits::*)()) &IntPatch_PrmPrmIntersection_T3Bits::ResetAnd, "None");
	cls_IntPatch_PrmPrmIntersection_T3Bits.def("And", (Standard_Integer (IntPatch_PrmPrmIntersection_T3Bits::*)(IntPatch_PrmPrmIntersection_T3Bits &, Standard_Integer &)) &IntPatch_PrmPrmIntersection_T3Bits::And, "None", py::arg("Oth"), py::arg("indiceprecedent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_PrmPrmIntersection.hxx
	py::class_<IntPatch_PrmPrmIntersection, std::unique_ptr<IntPatch_PrmPrmIntersection, Deleter<IntPatch_PrmPrmIntersection>>> cls_IntPatch_PrmPrmIntersection(mod, "IntPatch_PrmPrmIntersection", "Implementation of the Intersection between two bi-parametrised surfaces.");
	cls_IntPatch_PrmPrmIntersection.def(py::init<>());
	cls_IntPatch_PrmPrmIntersection.def("Perform", (void (IntPatch_PrmPrmIntersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const IntPatch_Polyhedron &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const IntPatch_Polyhedron &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_PrmPrmIntersection::Perform, "Performs the intersection between <Caro1> and <Caro2>. Associated Polyhedrons <Polyhedron1> and <Polyhedron2> are given.", py::arg("Caro1"), py::arg("Polyhedron1"), py::arg("Domain1"), py::arg("Caro2"), py::arg("Polyhedron2"), py::arg("Domain2"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"));
	cls_IntPatch_PrmPrmIntersection.def("Perform", (void (IntPatch_PrmPrmIntersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const IntPatch_Polyhedron &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_PrmPrmIntersection::Perform, "None", py::arg("Caro1"), py::arg("Polyhedron1"), py::arg("Domain1"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"));
	cls_IntPatch_PrmPrmIntersection.def("Perform", [](IntPatch_PrmPrmIntersection &self, const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_TopolTool> & a1, const opencascade::handle<Adaptor3d_HSurface> & a2, const opencascade::handle<Adaptor3d_TopolTool> & a3, const Standard_Real a4, const Standard_Real a5, const Standard_Real a6, const Standard_Real a7) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7); }, py::arg("Caro1"), py::arg("Domain1"), py::arg("Caro2"), py::arg("Domain2"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"));
	cls_IntPatch_PrmPrmIntersection.def("Perform", (void (IntPatch_PrmPrmIntersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &IntPatch_PrmPrmIntersection::Perform, "Performs the intersection between <Caro1> and <Caro2>. The method computes the polyhedron on each surface.", py::arg("Caro1"), py::arg("Domain1"), py::arg("Caro2"), py::arg("Domain2"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"), py::arg("ClearFlag"));
	cls_IntPatch_PrmPrmIntersection.def("Perform", (void (IntPatch_PrmPrmIntersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, IntSurf_ListOfPntOn2S &, const Standard_Boolean)) &IntPatch_PrmPrmIntersection::Perform, "Performs the intersection between <Caro1> and <Caro2>. The method computes the polyhedron on each surface.", py::arg("Caro1"), py::arg("Domain1"), py::arg("Caro2"), py::arg("Domain2"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"), py::arg("ListOfPnts"), py::arg("RestrictLine"));
	cls_IntPatch_PrmPrmIntersection.def("Perform", (void (IntPatch_PrmPrmIntersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_PrmPrmIntersection::Perform, "Performs the intersection between <Caro1> and <Caro2>. The method computes the polyhedron on each surface.", py::arg("Caro1"), py::arg("Domain1"), py::arg("Caro2"), py::arg("Domain2"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"));
	cls_IntPatch_PrmPrmIntersection.def("Perform", (void (IntPatch_PrmPrmIntersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_PrmPrmIntersection::Perform, "Performs the intersection between <Caro1> and <Caro2>. The method computes the polyhedron on each surface.", py::arg("Caro1"), py::arg("Domain1"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"));
	cls_IntPatch_PrmPrmIntersection.def("Perform", (void (IntPatch_PrmPrmIntersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const IntPatch_Polyhedron &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_PrmPrmIntersection::Perform, "Performs the intersection between <Caro1> and <Caro2>.", py::arg("Caro1"), py::arg("Domain1"), py::arg("Caro2"), py::arg("Polyhedron2"), py::arg("Domain2"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"));
	cls_IntPatch_PrmPrmIntersection.def("Perform", (void (IntPatch_PrmPrmIntersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const IntPatch_Polyhedron &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_PrmPrmIntersection::Perform, "Performs the intersection between <Caro1> and <Caro2>.", py::arg("Caro1"), py::arg("Polyhedron1"), py::arg("Domain1"), py::arg("Caro2"), py::arg("Domain2"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"));
	cls_IntPatch_PrmPrmIntersection.def("IsDone", (Standard_Boolean (IntPatch_PrmPrmIntersection::*)() const ) &IntPatch_PrmPrmIntersection::IsDone, "Returns true if the calculus was succesfull.");
	cls_IntPatch_PrmPrmIntersection.def("IsEmpty", (Standard_Boolean (IntPatch_PrmPrmIntersection::*)() const ) &IntPatch_PrmPrmIntersection::IsEmpty, "Returns true if the is no intersection.");
	cls_IntPatch_PrmPrmIntersection.def("NbLines", (Standard_Integer (IntPatch_PrmPrmIntersection::*)() const ) &IntPatch_PrmPrmIntersection::NbLines, "Returns the number of intersection lines.");
	cls_IntPatch_PrmPrmIntersection.def("Line", (const opencascade::handle<IntPatch_Line> & (IntPatch_PrmPrmIntersection::*)(const Standard_Integer) const ) &IntPatch_PrmPrmIntersection::Line, "Returns the line of range Index. An exception is raised if Index<=0 or Index>NbLine.", py::arg("Index"));
	cls_IntPatch_PrmPrmIntersection.def("NewLine", (opencascade::handle<IntPatch_Line> (IntPatch_PrmPrmIntersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer) const ) &IntPatch_PrmPrmIntersection::NewLine, "Computes about <NbPoints> Intersection Points on the Line <IndexLine> between the Points of Index <LowPoint> and <HighPoint>.", py::arg("Caro1"), py::arg("Caro2"), py::arg("IndexLine"), py::arg("LowPoint"), py::arg("HighPoint"), py::arg("NbPoints"));
	cls_IntPatch_PrmPrmIntersection.def("GrilleInteger", (Standard_Integer (IntPatch_PrmPrmIntersection::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer) const ) &IntPatch_PrmPrmIntersection::GrilleInteger, "None", py::arg("ix"), py::arg("iy"), py::arg("iz"));
	cls_IntPatch_PrmPrmIntersection.def("IntegerGrille", (void (IntPatch_PrmPrmIntersection::*)(const Standard_Integer, Standard_Integer &, Standard_Integer &, Standard_Integer &) const ) &IntPatch_PrmPrmIntersection::IntegerGrille, "None", py::arg("t"), py::arg("ix"), py::arg("iy"), py::arg("iz"));
	cls_IntPatch_PrmPrmIntersection.def("DansGrille", (Standard_Integer (IntPatch_PrmPrmIntersection::*)(const Standard_Integer) const ) &IntPatch_PrmPrmIntersection::DansGrille, "None", py::arg("t"));
	cls_IntPatch_PrmPrmIntersection.def("NbPointsGrille", (Standard_Integer (IntPatch_PrmPrmIntersection::*)() const ) &IntPatch_PrmPrmIntersection::NbPointsGrille, "None");
	cls_IntPatch_PrmPrmIntersection.def("RemplitLin", (void (IntPatch_PrmPrmIntersection::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, IntPatch_PrmPrmIntersection_T3Bits &) const ) &IntPatch_PrmPrmIntersection::RemplitLin, "None", py::arg("x1"), py::arg("y1"), py::arg("z1"), py::arg("x2"), py::arg("y2"), py::arg("z2"), py::arg("Map"));
	cls_IntPatch_PrmPrmIntersection.def("RemplitTri", (void (IntPatch_PrmPrmIntersection::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, IntPatch_PrmPrmIntersection_T3Bits &) const ) &IntPatch_PrmPrmIntersection::RemplitTri, "None", py::arg("x1"), py::arg("y1"), py::arg("z1"), py::arg("x2"), py::arg("y2"), py::arg("z2"), py::arg("x3"), py::arg("y3"), py::arg("z3"), py::arg("Map"));
	cls_IntPatch_PrmPrmIntersection.def("Remplit", (void (IntPatch_PrmPrmIntersection::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, IntPatch_PrmPrmIntersection_T3Bits &) const ) &IntPatch_PrmPrmIntersection::Remplit, "None", py::arg("a"), py::arg("b"), py::arg("c"), py::arg("Map"));
	cls_IntPatch_PrmPrmIntersection.def("CodeReject", (Standard_Integer (IntPatch_PrmPrmIntersection::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real) const ) &IntPatch_PrmPrmIntersection::CodeReject, "None", py::arg("x1"), py::arg("y1"), py::arg("z1"), py::arg("x2"), py::arg("y2"), py::arg("z2"), py::arg("x3"), py::arg("y3"), py::arg("z3"));
	cls_IntPatch_PrmPrmIntersection.def("PointDepart", (void (IntPatch_PrmPrmIntersection::*)(opencascade::handle<IntSurf_LineOn2S> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Integer) const ) &IntPatch_PrmPrmIntersection::PointDepart, "None", py::arg("LineOn2S"), py::arg("S1"), py::arg("SU1"), py::arg("SV1"), py::arg("S2"), py::arg("SU2"), py::arg("SV2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_RstInt.hxx
	py::class_<IntPatch_RstInt, std::unique_ptr<IntPatch_RstInt, Deleter<IntPatch_RstInt>>> cls_IntPatch_RstInt(mod, "IntPatch_RstInt", "trouver les points d intersection entre la ligne de cheminement et les arcs de restriction");
	cls_IntPatch_RstInt.def(py::init<>());
	cls_IntPatch_RstInt.def_static("PutVertexOnLine_", (void (*)(const opencascade::handle<IntPatch_Line> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Boolean, const Standard_Real)) &IntPatch_RstInt::PutVertexOnLine, "None", py::arg("L"), py::arg("Surf"), py::arg("Domain"), py::arg("OtherSurf"), py::arg("OnFirst"), py::arg("Tol"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_TheIWLineOfTheIWalking.hxx
	py::class_<IntPatch_TheIWLineOfTheIWalking, opencascade::handle<IntPatch_TheIWLineOfTheIWalking>, Standard_Transient> cls_IntPatch_TheIWLineOfTheIWalking(mod, "IntPatch_TheIWLineOfTheIWalking", "None");
	cls_IntPatch_TheIWLineOfTheIWalking.def(py::init<>());
	cls_IntPatch_TheIWLineOfTheIWalking.def(py::init<const IntSurf_Allocator &>(), py::arg("theAllocator"));
	cls_IntPatch_TheIWLineOfTheIWalking.def("Reverse", (void (IntPatch_TheIWLineOfTheIWalking::*)()) &IntPatch_TheIWLineOfTheIWalking::Reverse, "reverse the points in the line. Hasfirst, HasLast are kept.");
	cls_IntPatch_TheIWLineOfTheIWalking.def("Cut", (void (IntPatch_TheIWLineOfTheIWalking::*)(const Standard_Integer)) &IntPatch_TheIWLineOfTheIWalking::Cut, "Cut the line at the point of rank Index.", py::arg("Index"));
	cls_IntPatch_TheIWLineOfTheIWalking.def("AddPoint", (void (IntPatch_TheIWLineOfTheIWalking::*)(const IntSurf_PntOn2S &)) &IntPatch_TheIWLineOfTheIWalking::AddPoint, "Add a point in the line.", py::arg("P"));
	cls_IntPatch_TheIWLineOfTheIWalking.def("AddStatusFirst", (void (IntPatch_TheIWLineOfTheIWalking::*)(const Standard_Boolean, const Standard_Boolean)) &IntPatch_TheIWLineOfTheIWalking::AddStatusFirst, "None", py::arg("Closed"), py::arg("HasFirst"));
	cls_IntPatch_TheIWLineOfTheIWalking.def("AddStatusFirst", (void (IntPatch_TheIWLineOfTheIWalking::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Integer, const IntSurf_PathPoint &)) &IntPatch_TheIWLineOfTheIWalking::AddStatusFirst, "None", py::arg("Closed"), py::arg("HasLast"), py::arg("Index"), py::arg("P"));
	cls_IntPatch_TheIWLineOfTheIWalking.def("AddStatusFirstLast", (void (IntPatch_TheIWLineOfTheIWalking::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &IntPatch_TheIWLineOfTheIWalking::AddStatusFirstLast, "None", py::arg("Closed"), py::arg("HasFirst"), py::arg("HasLast"));
	cls_IntPatch_TheIWLineOfTheIWalking.def("AddStatusLast", (void (IntPatch_TheIWLineOfTheIWalking::*)(const Standard_Boolean)) &IntPatch_TheIWLineOfTheIWalking::AddStatusLast, "None", py::arg("HasLast"));
	cls_IntPatch_TheIWLineOfTheIWalking.def("AddStatusLast", (void (IntPatch_TheIWLineOfTheIWalking::*)(const Standard_Boolean, const Standard_Integer, const IntSurf_PathPoint &)) &IntPatch_TheIWLineOfTheIWalking::AddStatusLast, "None", py::arg("HasLast"), py::arg("Index"), py::arg("P"));
	cls_IntPatch_TheIWLineOfTheIWalking.def("AddIndexPassing", (void (IntPatch_TheIWLineOfTheIWalking::*)(const Standard_Integer)) &IntPatch_TheIWLineOfTheIWalking::AddIndexPassing, "associer a l 'indice du point sur la ligne l'indice du point passant dans l'iterateur de depart", py::arg("Index"));
	cls_IntPatch_TheIWLineOfTheIWalking.def("SetTangentVector", (void (IntPatch_TheIWLineOfTheIWalking::*)(const gp_Vec &, const Standard_Integer)) &IntPatch_TheIWLineOfTheIWalking::SetTangentVector, "None", py::arg("V"), py::arg("Index"));
	cls_IntPatch_TheIWLineOfTheIWalking.def("SetTangencyAtBegining", (void (IntPatch_TheIWLineOfTheIWalking::*)(const Standard_Boolean)) &IntPatch_TheIWLineOfTheIWalking::SetTangencyAtBegining, "None", py::arg("IsTangent"));
	cls_IntPatch_TheIWLineOfTheIWalking.def("SetTangencyAtEnd", (void (IntPatch_TheIWLineOfTheIWalking::*)(const Standard_Boolean)) &IntPatch_TheIWLineOfTheIWalking::SetTangencyAtEnd, "None", py::arg("IsTangent"));
	cls_IntPatch_TheIWLineOfTheIWalking.def("NbPoints", (Standard_Integer (IntPatch_TheIWLineOfTheIWalking::*)() const ) &IntPatch_TheIWLineOfTheIWalking::NbPoints, "Returns the number of points of the line (including first point and end point : see HasLastPoint and HasFirstPoint).");
	cls_IntPatch_TheIWLineOfTheIWalking.def("Value", (const IntSurf_PntOn2S & (IntPatch_TheIWLineOfTheIWalking::*)(const Standard_Integer) const ) &IntPatch_TheIWLineOfTheIWalking::Value, "Returns the point of range Index. If index <= 0 or Index > NbPoints, an exception is raised.", py::arg("Index"));
	cls_IntPatch_TheIWLineOfTheIWalking.def("Line", (const opencascade::handle<IntSurf_LineOn2S> & (IntPatch_TheIWLineOfTheIWalking::*)() const ) &IntPatch_TheIWLineOfTheIWalking::Line, "Returns the LineOn2S contained in the walking line.");
	cls_IntPatch_TheIWLineOfTheIWalking.def("IsClosed", (Standard_Boolean (IntPatch_TheIWLineOfTheIWalking::*)() const ) &IntPatch_TheIWLineOfTheIWalking::IsClosed, "Returns True if the line is closed.");
	cls_IntPatch_TheIWLineOfTheIWalking.def("HasFirstPoint", (Standard_Boolean (IntPatch_TheIWLineOfTheIWalking::*)() const ) &IntPatch_TheIWLineOfTheIWalking::HasFirstPoint, "Returns True if the first point of the line is a marching point . when is HasFirstPoint==False ,the line begins on the natural bound of the surface.the line can be too long");
	cls_IntPatch_TheIWLineOfTheIWalking.def("HasLastPoint", (Standard_Boolean (IntPatch_TheIWLineOfTheIWalking::*)() const ) &IntPatch_TheIWLineOfTheIWalking::HasLastPoint, "Returns True if the end point of the line is a marching point (Point from IntWS). when is HasFirstPoint==False ,the line ends on the natural bound of the surface.the line can be too long.");
	cls_IntPatch_TheIWLineOfTheIWalking.def("FirstPoint", (const IntSurf_PathPoint & (IntPatch_TheIWLineOfTheIWalking::*)() const ) &IntPatch_TheIWLineOfTheIWalking::FirstPoint, "Returns the first point of the line when it is a marching point. An exception is raised if HasFirstPoint returns False.");
	cls_IntPatch_TheIWLineOfTheIWalking.def("FirstPointIndex", (Standard_Integer (IntPatch_TheIWLineOfTheIWalking::*)() const ) &IntPatch_TheIWLineOfTheIWalking::FirstPointIndex, "Returns the Index of first point of the line when it is a marching point.This index is the index in the PointStartIterator. An exception is raised if HasFirstPoint returns False.");
	cls_IntPatch_TheIWLineOfTheIWalking.def("LastPoint", (const IntSurf_PathPoint & (IntPatch_TheIWLineOfTheIWalking::*)() const ) &IntPatch_TheIWLineOfTheIWalking::LastPoint, "Returns the last point of the line when it is a marching point. An exception is raised if HasLastPoint returns False.");
	cls_IntPatch_TheIWLineOfTheIWalking.def("LastPointIndex", (Standard_Integer (IntPatch_TheIWLineOfTheIWalking::*)() const ) &IntPatch_TheIWLineOfTheIWalking::LastPointIndex, "Returns the index of last point of the line when it is a marching point.This index is the index in the PointStartIterator. An exception is raised if HasLastPoint returns False.");
	cls_IntPatch_TheIWLineOfTheIWalking.def("NbPassingPoint", (Standard_Integer (IntPatch_TheIWLineOfTheIWalking::*)() const ) &IntPatch_TheIWLineOfTheIWalking::NbPassingPoint, "returns the number of points belonging to Pnts1 which are passing point.");
	cls_IntPatch_TheIWLineOfTheIWalking.def("PassingPoint", (void (IntPatch_TheIWLineOfTheIWalking::*)(const Standard_Integer, Standard_Integer &, Standard_Integer &) const ) &IntPatch_TheIWLineOfTheIWalking::PassingPoint, "returns the index of the point belonging to the line which is associated to the passing point belonging to Pnts1 an exception is raised if Index > NbPassingPoint()", py::arg("Index"), py::arg("IndexLine"), py::arg("IndexPnts"));
	cls_IntPatch_TheIWLineOfTheIWalking.def("TangentVector", (const gp_Vec & (IntPatch_TheIWLineOfTheIWalking::*)(Standard_Integer &) const ) &IntPatch_TheIWLineOfTheIWalking::TangentVector, "None", py::arg("Index"));
	cls_IntPatch_TheIWLineOfTheIWalking.def("IsTangentAtBegining", (Standard_Boolean (IntPatch_TheIWLineOfTheIWalking::*)() const ) &IntPatch_TheIWLineOfTheIWalking::IsTangentAtBegining, "None");
	cls_IntPatch_TheIWLineOfTheIWalking.def("IsTangentAtEnd", (Standard_Boolean (IntPatch_TheIWLineOfTheIWalking::*)() const ) &IntPatch_TheIWLineOfTheIWalking::IsTangentAtEnd, "None");
	cls_IntPatch_TheIWLineOfTheIWalking.def_static("get_type_name_", (const char * (*)()) &IntPatch_TheIWLineOfTheIWalking::get_type_name, "None");
	cls_IntPatch_TheIWLineOfTheIWalking.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntPatch_TheIWLineOfTheIWalking::get_type_descriptor, "None");
	cls_IntPatch_TheIWLineOfTheIWalking.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntPatch_TheIWLineOfTheIWalking::*)() const ) &IntPatch_TheIWLineOfTheIWalking::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_SpecialPoints.hxx
	py::class_<IntPatch_SpecialPoints, std::unique_ptr<IntPatch_SpecialPoints, Deleter<IntPatch_SpecialPoints>>> cls_IntPatch_SpecialPoints(mod, "IntPatch_SpecialPoints", "None");
	cls_IntPatch_SpecialPoints.def(py::init<>());
	cls_IntPatch_SpecialPoints.def_static("AddCrossUVIsoPoint_", [](const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_HSurface> & a1, const IntSurf_PntOn2S & a2, const Standard_Real a3, IntSurf_PntOn2S & a4) -> Standard_Boolean { return IntPatch_SpecialPoints::AddCrossUVIsoPoint(a0, a1, a2, a3, a4); }, py::arg("theQSurf"), py::arg("thePSurf"), py::arg("theRefPt"), py::arg("theTol3d"), py::arg("theAddedPoint"));
	cls_IntPatch_SpecialPoints.def_static("AddCrossUVIsoPoint_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const IntSurf_PntOn2S &, const Standard_Real, IntSurf_PntOn2S &, const Standard_Boolean)) &IntPatch_SpecialPoints::AddCrossUVIsoPoint, "Adds the point defined as intersection of two isolines (U = 0 and V = 0) on theQSurf in theLine. theRefPt is used to correct adjusting parameters. If theIsReversed is TRUE then theQSurf correspond to the second (otherwise, the first) surface while forming intersection point IntSurf_PntOn2S.", py::arg("theQSurf"), py::arg("thePSurf"), py::arg("theRefPt"), py::arg("theTol3d"), py::arg("theAddedPoint"), py::arg("theIsReversed"));
	cls_IntPatch_SpecialPoints.def_static("AddPointOnUorVIso_", [](const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_HSurface> & a1, const IntSurf_PntOn2S & a2, const Standard_Boolean a3, const math_Vector & a4, const math_Vector & a5, const math_Vector & a6, const math_Vector & a7, IntSurf_PntOn2S & a8) -> Standard_Boolean { return IntPatch_SpecialPoints::AddPointOnUorVIso(a0, a1, a2, a3, a4, a5, a6, a7, a8); }, py::arg("theQSurf"), py::arg("thePSurf"), py::arg("theRefPt"), py::arg("theIsU"), py::arg("theToler"), py::arg("theInitPoint"), py::arg("theInfBound"), py::arg("theSupBound"), py::arg("theAddedPoint"));
	cls_IntPatch_SpecialPoints.def_static("AddPointOnUorVIso_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const IntSurf_PntOn2S &, const Standard_Boolean, const math_Vector &, const math_Vector &, const math_Vector &, const math_Vector &, IntSurf_PntOn2S &, const Standard_Boolean)) &IntPatch_SpecialPoints::AddPointOnUorVIso, "Adds the point lain strictly in the isoline U = 0 or V = 0 of theQSurf, in theLine. theRefPt is used to correct adjusting parameters. If theIsReversed is TRUE then theQSurf corresponds to the second (otherwise, the first) surface while forming intersection point IntSurf_PntOn2S.", py::arg("theQSurf"), py::arg("thePSurf"), py::arg("theRefPt"), py::arg("theIsU"), py::arg("theToler"), py::arg("theInitPoint"), py::arg("theInfBound"), py::arg("theSupBound"), py::arg("theAddedPoint"), py::arg("theIsReversed"));
	cls_IntPatch_SpecialPoints.def_static("AddSingularPole_", [](const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_HSurface> & a1, const IntSurf_PntOn2S & a2, const Standard_Real a3, IntPatch_Point & a4, IntSurf_PntOn2S & a5) -> Standard_Boolean { return IntPatch_SpecialPoints::AddSingularPole(a0, a1, a2, a3, a4, a5); }, py::arg("theQSurf"), py::arg("thePSurf"), py::arg("thePtIso"), py::arg("theTol3d"), py::arg("theVertex"), py::arg("theAddedPoint"));
	cls_IntPatch_SpecialPoints.def_static("AddSingularPole_", [](const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_HSurface> & a1, const IntSurf_PntOn2S & a2, const Standard_Real a3, IntPatch_Point & a4, IntSurf_PntOn2S & a5, const Standard_Boolean a6) -> Standard_Boolean { return IntPatch_SpecialPoints::AddSingularPole(a0, a1, a2, a3, a4, a5, a6); }, py::arg("theQSurf"), py::arg("thePSurf"), py::arg("thePtIso"), py::arg("theTol3d"), py::arg("theVertex"), py::arg("theAddedPoint"), py::arg("theIsReversed"));
	cls_IntPatch_SpecialPoints.def_static("AddSingularPole_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const IntSurf_PntOn2S &, const Standard_Real, IntPatch_Point &, IntSurf_PntOn2S &, const Standard_Boolean, const Standard_Boolean)) &IntPatch_SpecialPoints::AddSingularPole, "Computes the pole of sphere to add it in the intersection line. Stores the result in theAddedPoint variable (does not add in the line). At that, cone and sphere (with singularity) must be set in theQSurf parameter. By default (if theIsReversed == FALSE), theQSurf is the first surface of the Walking line. If it is not, theIsReversed parameter must be set to TRUE. theIsReqRefCheck is TRUE if and only if 3D-point of theRefPt must be pole or apex for check (e.g. if it is vertex). thePtIso is the reference point for obtaining isoline where must be placed the Apex/Pole.", py::arg("theQSurf"), py::arg("thePSurf"), py::arg("thePtIso"), py::arg("theTol3d"), py::arg("theVertex"), py::arg("theAddedPoint"), py::arg("theIsReversed"), py::arg("theIsReqRefCheck"));
	cls_IntPatch_SpecialPoints.def_static("ContinueAfterSpecialPoint_", [](const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_HSurface> & a1, const IntSurf_PntOn2S & a2, const IntPatch_SpecPntType a3, const Standard_Real a4, IntSurf_PntOn2S & a5) -> Standard_Boolean { return IntPatch_SpecialPoints::ContinueAfterSpecialPoint(a0, a1, a2, a3, a4, a5); }, py::arg("theQSurf"), py::arg("thePSurf"), py::arg("theRefPt"), py::arg("theSPType"), py::arg("theTol2D"), py::arg("theNewPoint"));
	cls_IntPatch_SpecialPoints.def_static("ContinueAfterSpecialPoint_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const IntSurf_PntOn2S &, const IntPatch_SpecPntType, const Standard_Real, IntSurf_PntOn2S &, const Standard_Boolean)) &IntPatch_SpecialPoints::ContinueAfterSpecialPoint, "Special point has already been added in the line. Now, we need in correct prolongation of the line or in start new line. This function returns new point.", py::arg("theQSurf"), py::arg("thePSurf"), py::arg("theRefPt"), py::arg("theSPType"), py::arg("theTol2D"), py::arg("theNewPoint"), py::arg("theIsReversed"));
	// FIXME cls_IntPatch_SpecialPoints.def_static("AdjustPointAndVertex_", [](const IntSurf_PntOn2S & a0, const Standard_Real [4] a1, IntSurf_PntOn2S & a2) -> void { return IntPatch_SpecialPoints::AdjustPointAndVertex(a0, a1, a2); }, py::arg("theRefPoint"), py::arg("theArrPeriods"), py::arg("theNewPoint"));
	// FIXME cls_IntPatch_SpecialPoints.def_static("AdjustPointAndVertex_", (void (*)(const IntSurf_PntOn2S &, const Standard_Real [4], IntSurf_PntOn2S &, IntPatch_Point *const)) &IntPatch_SpecialPoints::AdjustPointAndVertex, "Sets theNewPoint parameters in 2D-space the closest to theRefPoint with help of adding/subtracting corresponding periods. theArrPeriods must be filled as follows: {<U-period of 1st surface>, <V-period of 1st surface>, <U-period of 2nd surface>, <V-period of 2nd surface>}. If theVertex != 0 then its parameters will be filled as corresponding parameters of theNewPoint.", py::arg("theRefPoint"), py::arg("theArrPeriods"), py::arg("theNewPoint"), py::arg("theVertex"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_TheIWalking.hxx
	py::class_<IntPatch_TheIWalking, std::unique_ptr<IntPatch_TheIWalking, Deleter<IntPatch_TheIWalking>>> cls_IntPatch_TheIWalking(mod, "IntPatch_TheIWalking", "None");
	cls_IntPatch_TheIWalking.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Step"));
	cls_IntPatch_TheIWalking.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Step"), py::arg("theToFillHoles"));
	cls_IntPatch_TheIWalking.def("SetTolerance", (void (IntPatch_TheIWalking::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_TheIWalking::SetTolerance, "Deflection is the maximum deflection admitted between two consecutive points on a resulting polyline. Step is the maximum increment admitted between two consecutive points (in 2d space). Epsilon is the tolerance beyond which 2 points are confused", py::arg("Epsilon"), py::arg("Deflection"), py::arg("Step"));
	cls_IntPatch_TheIWalking.def("Perform", [](IntPatch_TheIWalking &self, const IntSurf_SequenceOfPathPoint & a0, const IntSurf_SequenceOfInteriorPoint & a1, IntPatch_TheSurfFunction & a2, const opencascade::handle<Adaptor3d_HSurface> & a3) -> void { return self.Perform(a0, a1, a2, a3); }, py::arg("Pnts1"), py::arg("Pnts2"), py::arg("Func"), py::arg("S"));
	cls_IntPatch_TheIWalking.def("Perform", (void (IntPatch_TheIWalking::*)(const IntSurf_SequenceOfPathPoint &, const IntSurf_SequenceOfInteriorPoint &, IntPatch_TheSurfFunction &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Boolean)) &IntPatch_TheIWalking::Perform, "Searches a set of polylines starting on a point of Pnts1 or Pnts2. Each point on a resulting polyline verifies F(u,v)=0", py::arg("Pnts1"), py::arg("Pnts2"), py::arg("Func"), py::arg("S"), py::arg("Reversed"));
	cls_IntPatch_TheIWalking.def("Perform", [](IntPatch_TheIWalking &self, const IntSurf_SequenceOfPathPoint & a0, IntPatch_TheSurfFunction & a1, const opencascade::handle<Adaptor3d_HSurface> & a2) -> void { return self.Perform(a0, a1, a2); }, py::arg("Pnts1"), py::arg("Func"), py::arg("S"));
	cls_IntPatch_TheIWalking.def("Perform", (void (IntPatch_TheIWalking::*)(const IntSurf_SequenceOfPathPoint &, IntPatch_TheSurfFunction &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Boolean)) &IntPatch_TheIWalking::Perform, "Searches a set of polylines starting on a point of Pnts1. Each point on a resulting polyline verifies F(u,v)=0", py::arg("Pnts1"), py::arg("Func"), py::arg("S"), py::arg("Reversed"));
	cls_IntPatch_TheIWalking.def("IsDone", (Standard_Boolean (IntPatch_TheIWalking::*)() const ) &IntPatch_TheIWalking::IsDone, "Returns true if the calculus was successful.");
	cls_IntPatch_TheIWalking.def("NbLines", (Standard_Integer (IntPatch_TheIWalking::*)() const ) &IntPatch_TheIWalking::NbLines, "Returns the number of resulting polylines. An exception is raised if IsDone returns False.");
	cls_IntPatch_TheIWalking.def("Value", (const opencascade::handle<IntPatch_TheIWLineOfTheIWalking> & (IntPatch_TheIWalking::*)(const Standard_Integer) const ) &IntPatch_TheIWalking::Value, "Returns the polyline of range Index. An exception is raised if IsDone is False. An exception is raised if Index<=0 or Index>NbLines.", py::arg("Index"));
	cls_IntPatch_TheIWalking.def("NbSinglePnts", (Standard_Integer (IntPatch_TheIWalking::*)() const ) &IntPatch_TheIWalking::NbSinglePnts, "Returns the number of points belonging to Pnts on which no line starts or ends. An exception is raised if IsDone returns False.");
	cls_IntPatch_TheIWalking.def("SinglePnt", (const IntSurf_PathPoint & (IntPatch_TheIWalking::*)(const Standard_Integer) const ) &IntPatch_TheIWalking::SinglePnt, "Returns the point of range Index . An exception is raised if IsDone returns False. An exception is raised if Index<=0 or Index > NbSinglePnts.", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_WLineTool.hxx
	py::class_<IntPatch_WLineTool, std::unique_ptr<IntPatch_WLineTool, Deleter<IntPatch_WLineTool>>> cls_IntPatch_WLineTool(mod, "IntPatch_WLineTool", "IntPatch_WLineTool provides set of static methods related to walking lines.");
	cls_IntPatch_WLineTool.def(py::init<>());
	cls_IntPatch_WLineTool.def_static("ComputePurgedWLine_", (opencascade::handle<IntPatch_WLine> (*)(const opencascade::handle<IntPatch_WLine> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Boolean)) &IntPatch_WLineTool::ComputePurgedWLine, "I Removes equal points (leave one of equal points) from theWLine and recompute vertex parameters.", py::arg("theWLine"), py::arg("theS1"), py::arg("theS2"), py::arg("theDom1"), py::arg("theDom2"), py::arg("theRestrictLine"));
	cls_IntPatch_WLineTool.def_static("JoinWLines_", (void (*)(IntPatch_SequenceOfLine &, IntPatch_SequenceOfPoint &, opencascade::handle<Adaptor3d_HSurface>, opencascade::handle<Adaptor3d_HSurface>, const Standard_Real)) &IntPatch_WLineTool::JoinWLines, "Joins all WLines from theSlin to one if it is possible and records the result into theSlin again. Lines will be kept to be splitted if: a) they are separated (has no common points); b) resulted line (after joining) go through seam-edges or surface boundaries.", py::arg("theSlin"), py::arg("theSPnt"), py::arg("theS1"), py::arg("theS2"), py::arg("theTol3D"));
	cls_IntPatch_WLineTool.def_static("ExtendTwoWLines_", (void (*)(IntPatch_SequenceOfLine &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real *const, const Bnd_Box2d &, const Bnd_Box2d &)) &IntPatch_WLineTool::ExtendTwoWLines, "Extends every line from theSlin (if it is possible) to be started/finished in strictly determined point (in the place of joint of two lines). As result, some gaps between two lines will vanish. The Walking lines are supposed (algorithm will do nothing for not-Walking line) to be computed as a result of intersection. Both theS1 and theS2 must be quadrics. Other cases are not supported. theArrPeriods must be filled as follows (every value must not be negative; if the surface is not periodic the period must be equal to 0.0 strictly): {<U-period of 1st surface>, <V-period of 1st surface>, <U-period of 2nd surface>, <V-period of 2nd surface>}.", py::arg("theSlin"), py::arg("theS1"), py::arg("theS2"), py::arg("theToler3D"), py::arg("theArrPeriods"), py::arg("theBoxS1"), py::arg("theBoxS2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_SequenceOfPoint.hxx
	bind_NCollection_Sequence<IntPatch_Point>(mod, "IntPatch_SequenceOfPoint");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_SequenceOfLine.hxx
	bind_NCollection_Sequence<opencascade::handle<IntPatch_Line> >(mod, "IntPatch_SequenceOfLine");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_SequenceOfSegmentOfTheSOnBounds.hxx
	bind_NCollection_Sequence<IntPatch_TheSegmentOfTheSOnBounds>(mod, "IntPatch_SequenceOfSegmentOfTheSOnBounds");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_SequenceOfPathPointOfTheSOnBounds.hxx
	bind_NCollection_Sequence<IntPatch_ThePathPointOfTheSOnBounds>(mod, "IntPatch_SequenceOfPathPointOfTheSOnBounds");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_SearchPnt.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPatch_SequenceOfIWLineOfTheIWalking.hxx
	bind_NCollection_Sequence<opencascade::handle<IntPatch_TheIWLineOfTheIWalking> >(mod, "IntPatch_SequenceOfIWLineOfTheIWalking");


}
