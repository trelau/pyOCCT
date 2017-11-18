#include <pyOCCT_Common.hpp>

#include <Contap_TFunction.hxx>
#include <math_FunctionWithDerivative.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <IntSurf_Quadric.hxx>
#include <Contap_ArcFunction.hxx>
#include <gp_Sphere.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Cone.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Circ.hxx>
#include <gp_Lin.hxx>
#include <Contap_ContAna.hxx>
#include <Adaptor3d_HVertex.hxx>
#include <IntSurf_Transition.hxx>
#include <Contap_Point.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <Contap_TheSequenceOfPoint.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Type.hxx>
#include <Contap_TheHSequenceOfPoint.hxx>
#include <Contap_IType.hxx>
#include <IntSurf_LineOn2S.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <IntSurf_TypeTrans.hxx>
#include <Contap_Line.hxx>
#include <Contap_TheSequenceOfLine.hxx>
#include <Contap_ThePathPointOfTheSearch.hxx>
#include <Contap_TheSegmentOfTheSearch.hxx>
#include <Contap_SequenceOfSegmentOfTheSearch.hxx>
#include <Contap_SequenceOfPathPointOfTheSearch.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Parab2d.hxx>
#include <Geom2d_BezierCurve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Contap_HCurve2dTool.hxx>
#include <Contap_HContTool.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <Contap_TheSearch.hxx>
#include <math_FunctionSetWithDerivatives.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <gp_Vec.hxx>
#include <gp_Dir2d.hxx>
#include <Contap_SurfFunction.hxx>
#include <IntSurf_InteriorPoint.hxx>
#include <Contap_TheSearchInside.hxx>
#include <Contap_Contour.hxx>
#include <IntSurf_Allocator.hxx>
#include <IntSurf_PathPoint.hxx>
#include <Contap_TheIWLineOfTheIWalking.hxx>
#include <Contap_SequenceOfIWLineOfTheIWalking.hxx>
#include <Contap_SurfProps.hxx>
#include <IntSurf_SequenceOfPathPoint.hxx>
#include <IntSurf_SequenceOfInteriorPoint.hxx>
#include <Contap_TheIWalking.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(Contap, mod) {

	// IMPORT
	py::module::import("OCCT.math");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Adaptor3d");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Adaptor2d");
	py::module::import("OCCT.IntSurf");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.Geom2d");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_TFunction.hxx
	py::enum_<Contap_TFunction>(mod, "Contap_TFunction", "None")
		.value("Contap_ContourStd", Contap_TFunction::Contap_ContourStd)
		.value("Contap_ContourPrs", Contap_TFunction::Contap_ContourPrs)
		.value("Contap_DraftStd", Contap_TFunction::Contap_DraftStd)
		.value("Contap_DraftPrs", Contap_TFunction::Contap_DraftPrs)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_IType.hxx
	py::enum_<Contap_IType>(mod, "Contap_IType", "None")
		.value("Contap_Lin", Contap_IType::Contap_Lin)
		.value("Contap_Circle", Contap_IType::Contap_Circle)
		.value("Contap_Walking", Contap_IType::Contap_Walking)
		.value("Contap_Restriction", Contap_IType::Contap_Restriction)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_ArcFunction.hxx
	py::class_<Contap_ArcFunction, std::unique_ptr<Contap_ArcFunction, Deleter<Contap_ArcFunction>>, math_FunctionWithDerivative> cls_Contap_ArcFunction(mod, "Contap_ArcFunction", "None");
	cls_Contap_ArcFunction.def(py::init<>());
	cls_Contap_ArcFunction.def("Set", (void (Contap_ArcFunction::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Contap_ArcFunction::Set, "None", py::arg("S"));
	cls_Contap_ArcFunction.def("Set", (void (Contap_ArcFunction::*)(const gp_Dir &)) &Contap_ArcFunction::Set, "None", py::arg("Direction"));
	cls_Contap_ArcFunction.def("Set", (void (Contap_ArcFunction::*)(const gp_Dir &, const Standard_Real)) &Contap_ArcFunction::Set, "None", py::arg("Direction"), py::arg("Angle"));
	cls_Contap_ArcFunction.def("Set", (void (Contap_ArcFunction::*)(const gp_Pnt &)) &Contap_ArcFunction::Set, "None", py::arg("Eye"));
	cls_Contap_ArcFunction.def("Set", (void (Contap_ArcFunction::*)(const gp_Pnt &, const Standard_Real)) &Contap_ArcFunction::Set, "None", py::arg("Eye"), py::arg("Angle"));
	cls_Contap_ArcFunction.def("Set", (void (Contap_ArcFunction::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_ArcFunction::Set, "None", py::arg("A"));
	cls_Contap_ArcFunction.def("Value", (Standard_Boolean (Contap_ArcFunction::*)(const Standard_Real, Standard_Real &)) &Contap_ArcFunction::Value, "None", py::arg("X"), py::arg("F"));
	cls_Contap_ArcFunction.def("Derivative", (Standard_Boolean (Contap_ArcFunction::*)(const Standard_Real, Standard_Real &)) &Contap_ArcFunction::Derivative, "None", py::arg("X"), py::arg("D"));
	cls_Contap_ArcFunction.def("Values", (Standard_Boolean (Contap_ArcFunction::*)(const Standard_Real, Standard_Real &, Standard_Real &)) &Contap_ArcFunction::Values, "None", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_Contap_ArcFunction.def("NbSamples", (Standard_Integer (Contap_ArcFunction::*)() const ) &Contap_ArcFunction::NbSamples, "None");
	cls_Contap_ArcFunction.def("GetStateNumber", (Standard_Integer (Contap_ArcFunction::*)()) &Contap_ArcFunction::GetStateNumber, "None");
	cls_Contap_ArcFunction.def("Valpoint", (const gp_Pnt & (Contap_ArcFunction::*)(const Standard_Integer) const ) &Contap_ArcFunction::Valpoint, "None", py::arg("Index"));
	cls_Contap_ArcFunction.def("Quadric", (const IntSurf_Quadric & (Contap_ArcFunction::*)() const ) &Contap_ArcFunction::Quadric, "None");
	cls_Contap_ArcFunction.def("Surface", (const opencascade::handle<Adaptor3d_HSurface> & (Contap_ArcFunction::*)() const ) &Contap_ArcFunction::Surface, "Returns mySurf field");
	cls_Contap_ArcFunction.def("LastComputedPoint", (const gp_Pnt & (Contap_ArcFunction::*)() const ) &Contap_ArcFunction::LastComputedPoint, "Returns the point, which has been computed while the last calling Value() method");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_ContAna.hxx
	py::class_<Contap_ContAna, std::unique_ptr<Contap_ContAna, Deleter<Contap_ContAna>>> cls_Contap_ContAna(mod, "Contap_ContAna", "This class provides the computation of the contours for quadric surfaces.");
	cls_Contap_ContAna.def(py::init<>());
	cls_Contap_ContAna.def("Perform", (void (Contap_ContAna::*)(const gp_Sphere &, const gp_Dir &)) &Contap_ContAna::Perform, "None", py::arg("S"), py::arg("D"));
	cls_Contap_ContAna.def("Perform", (void (Contap_ContAna::*)(const gp_Sphere &, const gp_Dir &, const Standard_Real)) &Contap_ContAna::Perform, "None", py::arg("S"), py::arg("D"), py::arg("Ang"));
	cls_Contap_ContAna.def("Perform", (void (Contap_ContAna::*)(const gp_Sphere &, const gp_Pnt &)) &Contap_ContAna::Perform, "None", py::arg("S"), py::arg("Eye"));
	cls_Contap_ContAna.def("Perform", (void (Contap_ContAna::*)(const gp_Cylinder &, const gp_Dir &)) &Contap_ContAna::Perform, "None", py::arg("C"), py::arg("D"));
	cls_Contap_ContAna.def("Perform", (void (Contap_ContAna::*)(const gp_Cylinder &, const gp_Dir &, const Standard_Real)) &Contap_ContAna::Perform, "None", py::arg("C"), py::arg("D"), py::arg("Ang"));
	cls_Contap_ContAna.def("Perform", (void (Contap_ContAna::*)(const gp_Cylinder &, const gp_Pnt &)) &Contap_ContAna::Perform, "None", py::arg("C"), py::arg("Eye"));
	cls_Contap_ContAna.def("Perform", (void (Contap_ContAna::*)(const gp_Cone &, const gp_Dir &)) &Contap_ContAna::Perform, "None", py::arg("C"), py::arg("D"));
	cls_Contap_ContAna.def("Perform", (void (Contap_ContAna::*)(const gp_Cone &, const gp_Dir &, const Standard_Real)) &Contap_ContAna::Perform, "None", py::arg("C"), py::arg("D"), py::arg("Ang"));
	cls_Contap_ContAna.def("Perform", (void (Contap_ContAna::*)(const gp_Cone &, const gp_Pnt &)) &Contap_ContAna::Perform, "None", py::arg("C"), py::arg("Eye"));
	cls_Contap_ContAna.def("IsDone", (Standard_Boolean (Contap_ContAna::*)() const ) &Contap_ContAna::IsDone, "None");
	cls_Contap_ContAna.def("NbContours", (Standard_Integer (Contap_ContAna::*)() const ) &Contap_ContAna::NbContours, "None");
	cls_Contap_ContAna.def("TypeContour", (GeomAbs_CurveType (Contap_ContAna::*)() const ) &Contap_ContAna::TypeContour, "Returns GeomAbs_Line or GeomAbs_Circle, when IsDone() returns True.");
	cls_Contap_ContAna.def("Circle", (gp_Circ (Contap_ContAna::*)() const ) &Contap_ContAna::Circle, "None");
	cls_Contap_ContAna.def("Line", (gp_Lin (Contap_ContAna::*)(const Standard_Integer) const ) &Contap_ContAna::Line, "None", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_Point.hxx
	py::class_<Contap_Point, std::unique_ptr<Contap_Point, Deleter<Contap_Point>>> cls_Contap_Point(mod, "Contap_Point", "Definition of a vertex on the contour line. Most of the time, such a point is an intersection between the contour and a restriction of the surface. When it is not tyhe method IsOnArc return False. Such a point is contains geometrical informations (see the Value method) and logical informations.");
	cls_Contap_Point.def(py::init<>());
	cls_Contap_Point.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("Pt"), py::arg("U"), py::arg("V"));
	cls_Contap_Point.def("SetValue", (void (Contap_Point::*)(const gp_Pnt &, const Standard_Real, const Standard_Real)) &Contap_Point::SetValue, "Sets the values for a point.", py::arg("Pt"), py::arg("U"), py::arg("V"));
	cls_Contap_Point.def("SetParameter", (void (Contap_Point::*)(const Standard_Real)) &Contap_Point::SetParameter, "Set the value of the parameter on the intersection line.", py::arg("Para"));
	cls_Contap_Point.def("SetVertex", (void (Contap_Point::*)(const opencascade::handle<Adaptor3d_HVertex> &)) &Contap_Point::SetVertex, "Sets the values of a point which is a vertex on the initial facet of restriction of one of the surface.", py::arg("V"));
	cls_Contap_Point.def("SetArc", (void (Contap_Point::*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const IntSurf_Transition &, const IntSurf_Transition &)) &Contap_Point::SetArc, "Sets the value of the arc and of the parameter on this arc of the point.", py::arg("A"), py::arg("Param"), py::arg("TLine"), py::arg("TArc"));
	cls_Contap_Point.def("SetMultiple", (void (Contap_Point::*)()) &Contap_Point::SetMultiple, "None");
	cls_Contap_Point.def("SetInternal", (void (Contap_Point::*)()) &Contap_Point::SetInternal, "None");
	cls_Contap_Point.def("Value", (const gp_Pnt & (Contap_Point::*)() const ) &Contap_Point::Value, "Returns the intersection point (geometric information).");
	cls_Contap_Point.def("ParameterOnLine", (Standard_Real (Contap_Point::*)() const ) &Contap_Point::ParameterOnLine, "This method returns the parameter of the point on the intersection line. If the points does not belong to an intersection line, the value returned does not have any sens.");
	cls_Contap_Point.def("Parameters", (void (Contap_Point::*)(Standard_Real &, Standard_Real &) const ) &Contap_Point::Parameters, "Returns the parameters on the surface of the point.", py::arg("U1"), py::arg("V1"));
	cls_Contap_Point.def("IsOnArc", (Standard_Boolean (Contap_Point::*)() const ) &Contap_Point::IsOnArc, "Returns True when the point is an intersection between the contour and a restriction.");
	cls_Contap_Point.def("Arc", (const opencascade::handle<Adaptor2d_HCurve2d> & (Contap_Point::*)() const ) &Contap_Point::Arc, "Returns the arc of restriction containing the vertex.");
	cls_Contap_Point.def("ParameterOnArc", (Standard_Real (Contap_Point::*)() const ) &Contap_Point::ParameterOnArc, "Returns the parameter of the point on the arc returned by the method Arc().");
	cls_Contap_Point.def("TransitionOnLine", (const IntSurf_Transition & (Contap_Point::*)() const ) &Contap_Point::TransitionOnLine, "Returns the transition of the point on the contour.");
	cls_Contap_Point.def("TransitionOnArc", (const IntSurf_Transition & (Contap_Point::*)() const ) &Contap_Point::TransitionOnArc, "Returns the transition of the point on the arc.");
	cls_Contap_Point.def("IsVertex", (Standard_Boolean (Contap_Point::*)() const ) &Contap_Point::IsVertex, "Returns TRUE if the point is a vertex on the initial restriction facet of the surface.");
	cls_Contap_Point.def("Vertex", (const opencascade::handle<Adaptor3d_HVertex> & (Contap_Point::*)() const ) &Contap_Point::Vertex, "Returns the information about the point when it is on the domain of the patch, i-e when the function IsVertex returns True. Otherwise, an exception is raised.");
	cls_Contap_Point.def("IsMultiple", (Standard_Boolean (Contap_Point::*)() const ) &Contap_Point::IsMultiple, "Returns True if the point belongs to several lines.");
	cls_Contap_Point.def("IsInternal", (Standard_Boolean (Contap_Point::*)() const ) &Contap_Point::IsInternal, "Returns True if the point is an internal one, i.e if the tangent to the line on the point and the eye direction are parallel.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_TheSequenceOfPoint.hxx
	bind_NCollection_Sequence<Contap_Point>(mod, "Contap_TheSequenceOfPoint");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_Line.hxx
	py::class_<Contap_Line, std::unique_ptr<Contap_Line, Deleter<Contap_Line>>> cls_Contap_Line(mod, "Contap_Line", "None");
	cls_Contap_Line.def(py::init<>());
	cls_Contap_Line.def("SetLineOn2S", (void (Contap_Line::*)(const opencascade::handle<IntSurf_LineOn2S> &)) &Contap_Line::SetLineOn2S, "None", py::arg("L"));
	cls_Contap_Line.def("Clear", (void (Contap_Line::*)()) &Contap_Line::Clear, "None");
	cls_Contap_Line.def("LineOn2S", (const opencascade::handle<IntSurf_LineOn2S> & (Contap_Line::*)() const ) &Contap_Line::LineOn2S, "None");
	cls_Contap_Line.def("ResetSeqOfVertex", (void (Contap_Line::*)()) &Contap_Line::ResetSeqOfVertex, "None");
	cls_Contap_Line.def("Add", (void (Contap_Line::*)(const IntSurf_PntOn2S &)) &Contap_Line::Add, "None", py::arg("P"));
	cls_Contap_Line.def("SetValue", (void (Contap_Line::*)(const gp_Lin &)) &Contap_Line::SetValue, "None", py::arg("L"));
	cls_Contap_Line.def("SetValue", (void (Contap_Line::*)(const gp_Circ &)) &Contap_Line::SetValue, "None", py::arg("C"));
	cls_Contap_Line.def("SetValue", (void (Contap_Line::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_Line::SetValue, "None", py::arg("A"));
	cls_Contap_Line.def("Add", (void (Contap_Line::*)(const Contap_Point &)) &Contap_Line::Add, "None", py::arg("P"));
	cls_Contap_Line.def("NbVertex", (Standard_Integer (Contap_Line::*)() const ) &Contap_Line::NbVertex, "None");
	cls_Contap_Line.def("Vertex", (Contap_Point & (Contap_Line::*)(const Standard_Integer) const ) &Contap_Line::Vertex, "None", py::arg("Index"));
	cls_Contap_Line.def("TypeContour", (Contap_IType (Contap_Line::*)() const ) &Contap_Line::TypeContour, "Returns Contap_Lin for a line, Contap_Circle for a circle, and Contap_Walking for a Walking line, Contap_Restriction for a part of boundarie.");
	cls_Contap_Line.def("NbPnts", (Standard_Integer (Contap_Line::*)() const ) &Contap_Line::NbPnts, "None");
	cls_Contap_Line.def("Point", (const IntSurf_PntOn2S & (Contap_Line::*)(const Standard_Integer) const ) &Contap_Line::Point, "None", py::arg("Index"));
	cls_Contap_Line.def("Line", (gp_Lin (Contap_Line::*)() const ) &Contap_Line::Line, "None");
	cls_Contap_Line.def("Circle", (gp_Circ (Contap_Line::*)() const ) &Contap_Line::Circle, "None");
	cls_Contap_Line.def("Arc", (const opencascade::handle<Adaptor2d_HCurve2d> & (Contap_Line::*)() const ) &Contap_Line::Arc, "None");
	cls_Contap_Line.def("SetTransitionOnS", (void (Contap_Line::*)(const IntSurf_TypeTrans)) &Contap_Line::SetTransitionOnS, "Set The Tansition of the line.", py::arg("T"));
	cls_Contap_Line.def("TransitionOnS", (IntSurf_TypeTrans (Contap_Line::*)() const ) &Contap_Line::TransitionOnS, "returns IN if at the 'left' of the line, the normale of the surface is oriented to the observator.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_ThePathPointOfTheSearch.hxx
	py::class_<Contap_ThePathPointOfTheSearch, std::unique_ptr<Contap_ThePathPointOfTheSearch, Deleter<Contap_ThePathPointOfTheSearch>>> cls_Contap_ThePathPointOfTheSearch(mod, "Contap_ThePathPointOfTheSearch", "None");
	cls_Contap_ThePathPointOfTheSearch.def(py::init<>());
	cls_Contap_ThePathPointOfTheSearch.def(py::init<const gp_Pnt &, const Standard_Real, const opencascade::handle<Adaptor3d_HVertex> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real>(), py::arg("P"), py::arg("Tol"), py::arg("V"), py::arg("A"), py::arg("Parameter"));
	cls_Contap_ThePathPointOfTheSearch.def(py::init<const gp_Pnt &, const Standard_Real, const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real>(), py::arg("P"), py::arg("Tol"), py::arg("A"), py::arg("Parameter"));
	cls_Contap_ThePathPointOfTheSearch.def("SetValue", (void (Contap_ThePathPointOfTheSearch::*)(const gp_Pnt &, const Standard_Real, const opencascade::handle<Adaptor3d_HVertex> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real)) &Contap_ThePathPointOfTheSearch::SetValue, "None", py::arg("P"), py::arg("Tol"), py::arg("V"), py::arg("A"), py::arg("Parameter"));
	cls_Contap_ThePathPointOfTheSearch.def("SetValue", (void (Contap_ThePathPointOfTheSearch::*)(const gp_Pnt &, const Standard_Real, const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real)) &Contap_ThePathPointOfTheSearch::SetValue, "None", py::arg("P"), py::arg("Tol"), py::arg("A"), py::arg("Parameter"));
	cls_Contap_ThePathPointOfTheSearch.def("Value", (const gp_Pnt & (Contap_ThePathPointOfTheSearch::*)() const ) &Contap_ThePathPointOfTheSearch::Value, "None");
	cls_Contap_ThePathPointOfTheSearch.def("Tolerance", (Standard_Real (Contap_ThePathPointOfTheSearch::*)() const ) &Contap_ThePathPointOfTheSearch::Tolerance, "None");
	cls_Contap_ThePathPointOfTheSearch.def("IsNew", (Standard_Boolean (Contap_ThePathPointOfTheSearch::*)() const ) &Contap_ThePathPointOfTheSearch::IsNew, "None");
	cls_Contap_ThePathPointOfTheSearch.def("Vertex", (const opencascade::handle<Adaptor3d_HVertex> & (Contap_ThePathPointOfTheSearch::*)() const ) &Contap_ThePathPointOfTheSearch::Vertex, "None");
	cls_Contap_ThePathPointOfTheSearch.def("Arc", (const opencascade::handle<Adaptor2d_HCurve2d> & (Contap_ThePathPointOfTheSearch::*)() const ) &Contap_ThePathPointOfTheSearch::Arc, "None");
	cls_Contap_ThePathPointOfTheSearch.def("Parameter", (Standard_Real (Contap_ThePathPointOfTheSearch::*)() const ) &Contap_ThePathPointOfTheSearch::Parameter, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_TheSegmentOfTheSearch.hxx
	py::class_<Contap_TheSegmentOfTheSearch, std::unique_ptr<Contap_TheSegmentOfTheSearch, Deleter<Contap_TheSegmentOfTheSearch>>> cls_Contap_TheSegmentOfTheSearch(mod, "Contap_TheSegmentOfTheSearch", "None");
	cls_Contap_TheSegmentOfTheSearch.def(py::init<>());
	cls_Contap_TheSegmentOfTheSearch.def("SetValue", (void (Contap_TheSegmentOfTheSearch::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_TheSegmentOfTheSearch::SetValue, "Defines the concerned arc.", py::arg("A"));
	cls_Contap_TheSegmentOfTheSearch.def("SetLimitPoint", (void (Contap_TheSegmentOfTheSearch::*)(const Contap_ThePathPointOfTheSearch &, const Standard_Boolean)) &Contap_TheSegmentOfTheSearch::SetLimitPoint, "Defines the first point or the last point, depending on the value of the boolean First.", py::arg("V"), py::arg("First"));
	cls_Contap_TheSegmentOfTheSearch.def("Curve", (const opencascade::handle<Adaptor2d_HCurve2d> & (Contap_TheSegmentOfTheSearch::*)() const ) &Contap_TheSegmentOfTheSearch::Curve, "Returns the geometric curve on the surface 's domain which is solution.");
	cls_Contap_TheSegmentOfTheSearch.def("HasFirstPoint", (Standard_Boolean (Contap_TheSegmentOfTheSearch::*)() const ) &Contap_TheSegmentOfTheSearch::HasFirstPoint, "Returns True if there is a vertex (ThePathPoint) defining the lowest valid parameter on the arc.");
	cls_Contap_TheSegmentOfTheSearch.def("FirstPoint", (const Contap_ThePathPointOfTheSearch & (Contap_TheSegmentOfTheSearch::*)() const ) &Contap_TheSegmentOfTheSearch::FirstPoint, "Returns the first point.");
	cls_Contap_TheSegmentOfTheSearch.def("HasLastPoint", (Standard_Boolean (Contap_TheSegmentOfTheSearch::*)() const ) &Contap_TheSegmentOfTheSearch::HasLastPoint, "Returns True if there is a vertex (ThePathPoint) defining the greatest valid parameter on the arc.");
	cls_Contap_TheSegmentOfTheSearch.def("LastPoint", (const Contap_ThePathPointOfTheSearch & (Contap_TheSegmentOfTheSearch::*)() const ) &Contap_TheSegmentOfTheSearch::LastPoint, "Returns the last point.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_HCurve2dTool.hxx
	py::class_<Contap_HCurve2dTool, std::unique_ptr<Contap_HCurve2dTool, Deleter<Contap_HCurve2dTool>>> cls_Contap_HCurve2dTool(mod, "Contap_HCurve2dTool", "None");
	cls_Contap_HCurve2dTool.def(py::init<>());
	cls_Contap_HCurve2dTool.def_static("FirstParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HCurve2dTool::FirstParameter, "None", py::arg("C"));
	cls_Contap_HCurve2dTool.def_static("LastParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HCurve2dTool::LastParameter, "None", py::arg("C"));
	cls_Contap_HCurve2dTool.def_static("Continuity_", (GeomAbs_Shape (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HCurve2dTool::Continuity, "None", py::arg("C"));
	cls_Contap_HCurve2dTool.def_static("NbIntervals_", (Standard_Integer (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const GeomAbs_Shape)) &Contap_HCurve2dTool::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(myclass) >= <S>", py::arg("C"), py::arg("S"));
	cls_Contap_HCurve2dTool.def_static("Intervals_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &Contap_HCurve2dTool::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("C"), py::arg("T"), py::arg("S"));
	cls_Contap_HCurve2dTool.def_static("IsClosed_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HCurve2dTool::IsClosed, "None", py::arg("C"));
	cls_Contap_HCurve2dTool.def_static("IsPeriodic_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HCurve2dTool::IsPeriodic, "None", py::arg("C"));
	cls_Contap_HCurve2dTool.def_static("Period_", (Standard_Real (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HCurve2dTool::Period, "None", py::arg("C"));
	cls_Contap_HCurve2dTool.def_static("Value_", (gp_Pnt2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real)) &Contap_HCurve2dTool::Value, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"));
	cls_Contap_HCurve2dTool.def_static("D0_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, gp_Pnt2d &)) &Contap_HCurve2dTool::D0, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"), py::arg("P"));
	cls_Contap_HCurve2dTool.def_static("D1_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &)) &Contap_HCurve2dTool::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V"));
	cls_Contap_HCurve2dTool.def_static("D2_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &)) &Contap_HCurve2dTool::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_Contap_HCurve2dTool.def_static("D3_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &)) &Contap_HCurve2dTool::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_Contap_HCurve2dTool.def_static("DN_", (gp_Vec2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const Standard_Integer)) &Contap_HCurve2dTool::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("C"), py::arg("U"), py::arg("N"));
	cls_Contap_HCurve2dTool.def_static("Resolution_", (Standard_Real (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real)) &Contap_HCurve2dTool::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("C"), py::arg("R3d"));
	cls_Contap_HCurve2dTool.def_static("GetType_", (GeomAbs_CurveType (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HCurve2dTool::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.", py::arg("C"));
	cls_Contap_HCurve2dTool.def_static("Line_", (gp_Lin2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HCurve2dTool::Line, "None", py::arg("C"));
	cls_Contap_HCurve2dTool.def_static("Circle_", (gp_Circ2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HCurve2dTool::Circle, "None", py::arg("C"));
	cls_Contap_HCurve2dTool.def_static("Ellipse_", (gp_Elips2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HCurve2dTool::Ellipse, "None", py::arg("C"));
	cls_Contap_HCurve2dTool.def_static("Hyperbola_", (gp_Hypr2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HCurve2dTool::Hyperbola, "None", py::arg("C"));
	cls_Contap_HCurve2dTool.def_static("Parabola_", (gp_Parab2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HCurve2dTool::Parabola, "None", py::arg("C"));
	cls_Contap_HCurve2dTool.def_static("Bezier_", (opencascade::handle<Geom2d_BezierCurve> (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HCurve2dTool::Bezier, "None", py::arg("C"));
	cls_Contap_HCurve2dTool.def_static("BSpline_", (opencascade::handle<Geom2d_BSplineCurve> (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HCurve2dTool::BSpline, "None", py::arg("C"));
	cls_Contap_HCurve2dTool.def_static("NbSamples_", (Standard_Integer (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const Standard_Real)) &Contap_HCurve2dTool::NbSamples, "None", py::arg("C"), py::arg("U0"), py::arg("U1"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_HContTool.hxx
	py::class_<Contap_HContTool, std::unique_ptr<Contap_HContTool, Deleter<Contap_HContTool>>> cls_Contap_HContTool(mod, "Contap_HContTool", "Tool for the intersection between 2 surfaces. Regroupe pour l instant les methodes hors Adaptor3d...");
	cls_Contap_HContTool.def(py::init<>());
	cls_Contap_HContTool.def_static("NbSamplesU_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real)) &Contap_HContTool::NbSamplesU, "None", py::arg("S"), py::arg("u1"), py::arg("u2"));
	cls_Contap_HContTool.def_static("NbSamplesV_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real)) &Contap_HContTool::NbSamplesV, "None", py::arg("S"), py::arg("v1"), py::arg("v2"));
	cls_Contap_HContTool.def_static("NbSamplePoints_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Contap_HContTool::NbSamplePoints, "None", py::arg("S"));
	cls_Contap_HContTool.def_static("SamplePoint_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, Standard_Real &, Standard_Real &)) &Contap_HContTool::SamplePoint, "None", py::arg("S"), py::arg("Index"), py::arg("U"), py::arg("V"));
	cls_Contap_HContTool.def_static("HasBeenSeen_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HContTool::HasBeenSeen, "Returns True if all the intersection point and edges are known on the Arc. The intersection point are given as vertices. The intersection edges are given as intervals between two vertices.", py::arg("C"));
	cls_Contap_HContTool.def_static("NbSamplesOnArc_", (Standard_Integer (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HContTool::NbSamplesOnArc, "returns the number of points which is used to make a sample on the arc. this number is a function of the Surface and the CurveOnSurface complexity.", py::arg("A"));
	cls_Contap_HContTool.def_static("Bounds_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, Standard_Real &, Standard_Real &)) &Contap_HContTool::Bounds, "Returns the parametric limits on the arc C. These limits must be finite : they are either the real limits of the arc, for a finite arc, or a bounding box for an infinite arc.", py::arg("C"), py::arg("Ufirst"), py::arg("Ulast"));
	cls_Contap_HContTool.def_static("Project_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const gp_Pnt2d &, Standard_Real &, gp_Pnt2d &)) &Contap_HContTool::Project, "Projects the point P on the arc C. If the methods returns Standard_True, the projection is successful, and Paramproj is the parameter on the arc of the projected point, Ptproj is the projected Point. If the method returns Standard_False, Param proj and Ptproj are not significant.", py::arg("C"), py::arg("P"), py::arg("Paramproj"), py::arg("Ptproj"));
	cls_Contap_HContTool.def_static("Tolerance_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HVertex> &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HContTool::Tolerance, "Returns the parametric tolerance used to consider that the vertex and another point meet, i-e if Abs(parameter(Vertex) - parameter(OtherPnt))<= Tolerance, the points are 'merged'.", py::arg("V"), py::arg("C"));
	cls_Contap_HContTool.def_static("Parameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HVertex> &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HContTool::Parameter, "Returns the parameter of the vertex V on the arc A.", py::arg("V"), py::arg("C"));
	cls_Contap_HContTool.def_static("NbPoints_", (Standard_Integer (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HContTool::NbPoints, "Returns the number of intersection points on the arc A.", py::arg("C"));
	cls_Contap_HContTool.def_static("Value_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Integer, gp_Pnt &, Standard_Real &, Standard_Real &)) &Contap_HContTool::Value, "Returns the value (Pt), the tolerance (Tol), and the parameter (U) on the arc A , of the intersection point of range Index.", py::arg("C"), py::arg("Index"), py::arg("Pt"), py::arg("Tol"), py::arg("U"));
	cls_Contap_HContTool.def_static("IsVertex_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Integer)) &Contap_HContTool::IsVertex, "Returns True if the intersection point of range Index corresponds with a vertex on the arc A.", py::arg("C"), py::arg("Index"));
	cls_Contap_HContTool.def_static("Vertex_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Integer, opencascade::handle<Adaptor3d_HVertex> &)) &Contap_HContTool::Vertex, "When IsVertex returns True, this method returns the vertex on the arc A.", py::arg("C"), py::arg("Index"), py::arg("V"));
	cls_Contap_HContTool.def_static("NbSegments_", (Standard_Integer (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HContTool::NbSegments, "returns the number of part of A solution of the of intersection problem.", py::arg("C"));
	cls_Contap_HContTool.def_static("HasFirstPoint_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Integer, Standard_Integer &)) &Contap_HContTool::HasFirstPoint, "Returns True when the segment of range Index is not open at the left side. In that case, IndFirst is the range in the list intersection points (see NbPoints) of the one which defines the left bound of the segment. Otherwise, the method has to return False, and IndFirst has no meaning.", py::arg("C"), py::arg("Index"), py::arg("IndFirst"));
	cls_Contap_HContTool.def_static("HasLastPoint_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Integer, Standard_Integer &)) &Contap_HContTool::HasLastPoint, "Returns True when the segment of range Index is not open at the right side. In that case, IndLast is the range in the list intersection points (see NbPoints) of the one which defines the right bound of the segment. Otherwise, the method has to return False, and IndLast has no meaning.", py::arg("C"), py::arg("Index"), py::arg("IndLast"));
	cls_Contap_HContTool.def_static("IsAllSolution_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HContTool::IsAllSolution, "Returns True when the whole restriction is solution of the intersection problem.", py::arg("C"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_TheSearch.hxx
	py::class_<Contap_TheSearch, std::unique_ptr<Contap_TheSearch, Deleter<Contap_TheSearch>>> cls_Contap_TheSearch(mod, "Contap_TheSearch", "None");
	cls_Contap_TheSearch.def(py::init<>());
	cls_Contap_TheSearch.def("Perform", [](Contap_TheSearch &self, Contap_ArcFunction & a0, const opencascade::handle<Adaptor3d_TopolTool> & a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Perform(a0, a1, a2, a3); }, py::arg("F"), py::arg("Domain"), py::arg("TolBoundary"), py::arg("TolTangency"));
	cls_Contap_TheSearch.def("Perform", (void (Contap_TheSearch::*)(Contap_ArcFunction &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Contap_TheSearch::Perform, "Algorithm to find the points and parts of curves of Domain (domain of of restriction of a surface) which verify F = 0. TolBoundary defines if a curve is on Q. TolTangency defines if a point is on Q.", py::arg("F"), py::arg("Domain"), py::arg("TolBoundary"), py::arg("TolTangency"), py::arg("RecheckOnRegularity"));
	cls_Contap_TheSearch.def("IsDone", (Standard_Boolean (Contap_TheSearch::*)() const ) &Contap_TheSearch::IsDone, "Returns True if the calculus was successful.");
	cls_Contap_TheSearch.def("AllArcSolution", (Standard_Boolean (Contap_TheSearch::*)() const ) &Contap_TheSearch::AllArcSolution, "Returns true if all arc of the Arcs are solution (inside the surface). An exception is raised if IsDone returns False.");
	cls_Contap_TheSearch.def("NbPoints", (Standard_Integer (Contap_TheSearch::*)() const ) &Contap_TheSearch::NbPoints, "Returns the number of resulting points. An exception is raised if IsDone returns False (NotDone).");
	cls_Contap_TheSearch.def("Point", (const Contap_ThePathPointOfTheSearch & (Contap_TheSearch::*)(const Standard_Integer) const ) &Contap_TheSearch::Point, "Returns the resulting point of range Index. The exception NotDone is raised if IsDone() returns False. The exception OutOfRange is raised if Index <= 0 or Index > NbPoints.", py::arg("Index"));
	cls_Contap_TheSearch.def("NbSegments", (Standard_Integer (Contap_TheSearch::*)() const ) &Contap_TheSearch::NbSegments, "Returns the number of the resulting segments. An exception is raised if IsDone returns False (NotDone).");
	cls_Contap_TheSearch.def("Segment", (const Contap_TheSegmentOfTheSearch & (Contap_TheSearch::*)(const Standard_Integer) const ) &Contap_TheSearch::Segment, "Returns the resulting segment of range Index. The exception NotDone is raised if IsDone() returns False. The exception OutOfRange is raised if Index <= 0 or Index > NbPoints.", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_SurfFunction.hxx
	py::class_<Contap_SurfFunction, std::unique_ptr<Contap_SurfFunction, Deleter<Contap_SurfFunction>>, math_FunctionSetWithDerivatives> cls_Contap_SurfFunction(mod, "Contap_SurfFunction", "This class describes the function on a parametric surface. the form of the function is F(u,v) = 0 where u and v are the parameteric coordinates of a point on the surface, to compute the contours of the surface.");
	cls_Contap_SurfFunction.def(py::init<>());
	cls_Contap_SurfFunction.def("Set", (void (Contap_SurfFunction::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Contap_SurfFunction::Set, "None", py::arg("S"));
	cls_Contap_SurfFunction.def("Set", (void (Contap_SurfFunction::*)(const gp_Pnt &)) &Contap_SurfFunction::Set, "None", py::arg("Eye"));
	cls_Contap_SurfFunction.def("Set", (void (Contap_SurfFunction::*)(const gp_Dir &)) &Contap_SurfFunction::Set, "None", py::arg("Dir"));
	cls_Contap_SurfFunction.def("Set", (void (Contap_SurfFunction::*)(const gp_Dir &, const Standard_Real)) &Contap_SurfFunction::Set, "None", py::arg("Dir"), py::arg("Angle"));
	cls_Contap_SurfFunction.def("Set", (void (Contap_SurfFunction::*)(const gp_Pnt &, const Standard_Real)) &Contap_SurfFunction::Set, "None", py::arg("Eye"), py::arg("Angle"));
	cls_Contap_SurfFunction.def("Set", (void (Contap_SurfFunction::*)(const Standard_Real)) &Contap_SurfFunction::Set, "None", py::arg("Tolerance"));
	cls_Contap_SurfFunction.def("NbVariables", (Standard_Integer (Contap_SurfFunction::*)() const ) &Contap_SurfFunction::NbVariables, "This method has to return 2.");
	cls_Contap_SurfFunction.def("NbEquations", (Standard_Integer (Contap_SurfFunction::*)() const ) &Contap_SurfFunction::NbEquations, "This method has to return 1.");
	cls_Contap_SurfFunction.def("Value", (Standard_Boolean (Contap_SurfFunction::*)(const math_Vector &, math_Vector &)) &Contap_SurfFunction::Value, "The dimension of F is 1.", py::arg("X"), py::arg("F"));
	cls_Contap_SurfFunction.def("Derivatives", (Standard_Boolean (Contap_SurfFunction::*)(const math_Vector &, math_Matrix &)) &Contap_SurfFunction::Derivatives, "The dimension of D is (1,2).", py::arg("X"), py::arg("D"));
	cls_Contap_SurfFunction.def("Values", (Standard_Boolean (Contap_SurfFunction::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Contap_SurfFunction::Values, "None", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_Contap_SurfFunction.def("Root", (Standard_Real (Contap_SurfFunction::*)() const ) &Contap_SurfFunction::Root, "Root is the value of the function at the solution. It is a vector of dimension 1, i-e a real.");
	cls_Contap_SurfFunction.def("Tolerance", (Standard_Real (Contap_SurfFunction::*)() const ) &Contap_SurfFunction::Tolerance, "Returns the value Tol so that if Abs(Func.Root())<Tol the function is considered null.");
	cls_Contap_SurfFunction.def("Point", (const gp_Pnt & (Contap_SurfFunction::*)() const ) &Contap_SurfFunction::Point, "Returns the value of the solution point on the surface.");
	cls_Contap_SurfFunction.def("IsTangent", (Standard_Boolean (Contap_SurfFunction::*)()) &Contap_SurfFunction::IsTangent, "None");
	cls_Contap_SurfFunction.def("Direction3d", (const gp_Vec & (Contap_SurfFunction::*)()) &Contap_SurfFunction::Direction3d, "None");
	cls_Contap_SurfFunction.def("Direction2d", (const gp_Dir2d & (Contap_SurfFunction::*)()) &Contap_SurfFunction::Direction2d, "None");
	cls_Contap_SurfFunction.def("FunctionType", (Contap_TFunction (Contap_SurfFunction::*)() const ) &Contap_SurfFunction::FunctionType, "None");
	cls_Contap_SurfFunction.def("Eye", (const gp_Pnt & (Contap_SurfFunction::*)() const ) &Contap_SurfFunction::Eye, "None");
	cls_Contap_SurfFunction.def("Direction", (const gp_Dir & (Contap_SurfFunction::*)() const ) &Contap_SurfFunction::Direction, "None");
	cls_Contap_SurfFunction.def("Angle", (Standard_Real (Contap_SurfFunction::*)() const ) &Contap_SurfFunction::Angle, "None");
	cls_Contap_SurfFunction.def("Surface", (const opencascade::handle<Adaptor3d_HSurface> & (Contap_SurfFunction::*)() const ) &Contap_SurfFunction::Surface, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_TheSearchInside.hxx
	py::class_<Contap_TheSearchInside, std::unique_ptr<Contap_TheSearchInside, Deleter<Contap_TheSearchInside>>> cls_Contap_TheSearchInside(mod, "Contap_TheSearchInside", "None");
	cls_Contap_TheSearchInside.def(py::init<>());
	cls_Contap_TheSearchInside.def(py::init<Contap_SurfFunction &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real>(), py::arg("F"), py::arg("Surf"), py::arg("T"), py::arg("Epsilon"));
	cls_Contap_TheSearchInside.def("Perform", (void (Contap_TheSearchInside::*)(Contap_SurfFunction &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real)) &Contap_TheSearchInside::Perform, "None", py::arg("F"), py::arg("Surf"), py::arg("T"), py::arg("Epsilon"));
	cls_Contap_TheSearchInside.def("Perform", (void (Contap_TheSearchInside::*)(Contap_SurfFunction &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real)) &Contap_TheSearchInside::Perform, "None", py::arg("F"), py::arg("Surf"), py::arg("UStart"), py::arg("VStart"));
	cls_Contap_TheSearchInside.def("IsDone", (Standard_Boolean (Contap_TheSearchInside::*)() const ) &Contap_TheSearchInside::IsDone, "None");
	cls_Contap_TheSearchInside.def("NbPoints", (Standard_Integer (Contap_TheSearchInside::*)() const ) &Contap_TheSearchInside::NbPoints, "Returns the number of points. The exception NotDone if raised if IsDone returns False.");
	cls_Contap_TheSearchInside.def("Value", (const IntSurf_InteriorPoint & (Contap_TheSearchInside::*)(const Standard_Integer) const ) &Contap_TheSearchInside::Value, "Returns the point of range Index. The exception NotDone if raised if IsDone returns False. The exception OutOfRange if raised if Index <= 0 or Index > NbPoints.", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_Contour.hxx
	py::class_<Contap_Contour, std::unique_ptr<Contap_Contour, Deleter<Contap_Contour>>> cls_Contap_Contour(mod, "Contap_Contour", "None");
	cls_Contap_Contour.def(py::init<>());
	cls_Contap_Contour.def(py::init<const gp_Vec &>(), py::arg("Direction"));
	cls_Contap_Contour.def(py::init<const gp_Vec &, const Standard_Real>(), py::arg("Direction"), py::arg("Angle"));
	cls_Contap_Contour.def(py::init<const gp_Pnt &>(), py::arg("Eye"));
	cls_Contap_Contour.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const gp_Vec &>(), py::arg("Surf"), py::arg("Domain"), py::arg("Direction"));
	cls_Contap_Contour.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const gp_Vec &, const Standard_Real>(), py::arg("Surf"), py::arg("Domain"), py::arg("Direction"), py::arg("Angle"));
	cls_Contap_Contour.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const gp_Pnt &>(), py::arg("Surf"), py::arg("Domain"), py::arg("Eye"));
	cls_Contap_Contour.def("Perform", (void (Contap_Contour::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &)) &Contap_Contour::Perform, "Creates the contour in a given direction.", py::arg("Surf"), py::arg("Domain"));
	cls_Contap_Contour.def("Perform", (void (Contap_Contour::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const gp_Vec &)) &Contap_Contour::Perform, "Creates the contour in a given direction.", py::arg("Surf"), py::arg("Domain"), py::arg("Direction"));
	cls_Contap_Contour.def("Perform", (void (Contap_Contour::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const gp_Vec &, const Standard_Real)) &Contap_Contour::Perform, "Creates the contour in a given direction.", py::arg("Surf"), py::arg("Domain"), py::arg("Direction"), py::arg("Angle"));
	cls_Contap_Contour.def("Perform", (void (Contap_Contour::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const gp_Pnt &)) &Contap_Contour::Perform, "Creates the contour for a perspective view.", py::arg("Surf"), py::arg("Domain"), py::arg("Eye"));
	cls_Contap_Contour.def("Init", (void (Contap_Contour::*)(const gp_Vec &)) &Contap_Contour::Init, "None", py::arg("Direction"));
	cls_Contap_Contour.def("Init", (void (Contap_Contour::*)(const gp_Vec &, const Standard_Real)) &Contap_Contour::Init, "None", py::arg("Direction"), py::arg("Angle"));
	cls_Contap_Contour.def("Init", (void (Contap_Contour::*)(const gp_Pnt &)) &Contap_Contour::Init, "None", py::arg("Eye"));
	cls_Contap_Contour.def("IsDone", (Standard_Boolean (Contap_Contour::*)() const ) &Contap_Contour::IsDone, "None");
	cls_Contap_Contour.def("IsEmpty", (Standard_Boolean (Contap_Contour::*)() const ) &Contap_Contour::IsEmpty, "Returns true if the is no line.");
	cls_Contap_Contour.def("NbLines", (Standard_Integer (Contap_Contour::*)() const ) &Contap_Contour::NbLines, "None");
	cls_Contap_Contour.def("Line", (const Contap_Line & (Contap_Contour::*)(const Standard_Integer) const ) &Contap_Contour::Line, "None", py::arg("Index"));
	cls_Contap_Contour.def("SurfaceFunction", (Contap_SurfFunction & (Contap_Contour::*)()) &Contap_Contour::SurfaceFunction, "Returns a reference on the internal SurfaceFunction. This is used to compute tangents on the lines.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_TheIWLineOfTheIWalking.hxx
	py::class_<Contap_TheIWLineOfTheIWalking, opencascade::handle<Contap_TheIWLineOfTheIWalking>, Standard_Transient> cls_Contap_TheIWLineOfTheIWalking(mod, "Contap_TheIWLineOfTheIWalking", "None");
	cls_Contap_TheIWLineOfTheIWalking.def(py::init<>());
	cls_Contap_TheIWLineOfTheIWalking.def(py::init<const IntSurf_Allocator &>(), py::arg("theAllocator"));
	cls_Contap_TheIWLineOfTheIWalking.def("Reverse", (void (Contap_TheIWLineOfTheIWalking::*)()) &Contap_TheIWLineOfTheIWalking::Reverse, "reverse the points in the line. Hasfirst, HasLast are kept.");
	cls_Contap_TheIWLineOfTheIWalking.def("Cut", (void (Contap_TheIWLineOfTheIWalking::*)(const Standard_Integer)) &Contap_TheIWLineOfTheIWalking::Cut, "Cut the line at the point of rank Index.", py::arg("Index"));
	cls_Contap_TheIWLineOfTheIWalking.def("AddPoint", (void (Contap_TheIWLineOfTheIWalking::*)(const IntSurf_PntOn2S &)) &Contap_TheIWLineOfTheIWalking::AddPoint, "Add a point in the line.", py::arg("P"));
	cls_Contap_TheIWLineOfTheIWalking.def("AddStatusFirst", (void (Contap_TheIWLineOfTheIWalking::*)(const Standard_Boolean, const Standard_Boolean)) &Contap_TheIWLineOfTheIWalking::AddStatusFirst, "None", py::arg("Closed"), py::arg("HasFirst"));
	cls_Contap_TheIWLineOfTheIWalking.def("AddStatusFirst", (void (Contap_TheIWLineOfTheIWalking::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Integer, const IntSurf_PathPoint &)) &Contap_TheIWLineOfTheIWalking::AddStatusFirst, "None", py::arg("Closed"), py::arg("HasLast"), py::arg("Index"), py::arg("P"));
	cls_Contap_TheIWLineOfTheIWalking.def("AddStatusFirstLast", (void (Contap_TheIWLineOfTheIWalking::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &Contap_TheIWLineOfTheIWalking::AddStatusFirstLast, "None", py::arg("Closed"), py::arg("HasFirst"), py::arg("HasLast"));
	cls_Contap_TheIWLineOfTheIWalking.def("AddStatusLast", (void (Contap_TheIWLineOfTheIWalking::*)(const Standard_Boolean)) &Contap_TheIWLineOfTheIWalking::AddStatusLast, "None", py::arg("HasLast"));
	cls_Contap_TheIWLineOfTheIWalking.def("AddStatusLast", (void (Contap_TheIWLineOfTheIWalking::*)(const Standard_Boolean, const Standard_Integer, const IntSurf_PathPoint &)) &Contap_TheIWLineOfTheIWalking::AddStatusLast, "None", py::arg("HasLast"), py::arg("Index"), py::arg("P"));
	cls_Contap_TheIWLineOfTheIWalking.def("AddIndexPassing", (void (Contap_TheIWLineOfTheIWalking::*)(const Standard_Integer)) &Contap_TheIWLineOfTheIWalking::AddIndexPassing, "associer a l 'indice du point sur la ligne l'indice du point passant dans l'iterateur de depart", py::arg("Index"));
	cls_Contap_TheIWLineOfTheIWalking.def("SetTangentVector", (void (Contap_TheIWLineOfTheIWalking::*)(const gp_Vec &, const Standard_Integer)) &Contap_TheIWLineOfTheIWalking::SetTangentVector, "None", py::arg("V"), py::arg("Index"));
	cls_Contap_TheIWLineOfTheIWalking.def("SetTangencyAtBegining", (void (Contap_TheIWLineOfTheIWalking::*)(const Standard_Boolean)) &Contap_TheIWLineOfTheIWalking::SetTangencyAtBegining, "None", py::arg("IsTangent"));
	cls_Contap_TheIWLineOfTheIWalking.def("SetTangencyAtEnd", (void (Contap_TheIWLineOfTheIWalking::*)(const Standard_Boolean)) &Contap_TheIWLineOfTheIWalking::SetTangencyAtEnd, "None", py::arg("IsTangent"));
	cls_Contap_TheIWLineOfTheIWalking.def("NbPoints", (Standard_Integer (Contap_TheIWLineOfTheIWalking::*)() const ) &Contap_TheIWLineOfTheIWalking::NbPoints, "Returns the number of points of the line (including first point and end point : see HasLastPoint and HasFirstPoint).");
	cls_Contap_TheIWLineOfTheIWalking.def("Value", (const IntSurf_PntOn2S & (Contap_TheIWLineOfTheIWalking::*)(const Standard_Integer) const ) &Contap_TheIWLineOfTheIWalking::Value, "Returns the point of range Index. If index <= 0 or Index > NbPoints, an exception is raised.", py::arg("Index"));
	cls_Contap_TheIWLineOfTheIWalking.def("Line", (const opencascade::handle<IntSurf_LineOn2S> & (Contap_TheIWLineOfTheIWalking::*)() const ) &Contap_TheIWLineOfTheIWalking::Line, "Returns the LineOn2S contained in the walking line.");
	cls_Contap_TheIWLineOfTheIWalking.def("IsClosed", (Standard_Boolean (Contap_TheIWLineOfTheIWalking::*)() const ) &Contap_TheIWLineOfTheIWalking::IsClosed, "Returns True if the line is closed.");
	cls_Contap_TheIWLineOfTheIWalking.def("HasFirstPoint", (Standard_Boolean (Contap_TheIWLineOfTheIWalking::*)() const ) &Contap_TheIWLineOfTheIWalking::HasFirstPoint, "Returns True if the first point of the line is a marching point . when is HasFirstPoint==False ,the line begins on the natural bound of the surface.the line can be too long");
	cls_Contap_TheIWLineOfTheIWalking.def("HasLastPoint", (Standard_Boolean (Contap_TheIWLineOfTheIWalking::*)() const ) &Contap_TheIWLineOfTheIWalking::HasLastPoint, "Returns True if the end point of the line is a marching point (Point from IntWS). when is HasFirstPoint==False ,the line ends on the natural bound of the surface.the line can be too long.");
	cls_Contap_TheIWLineOfTheIWalking.def("FirstPoint", (const IntSurf_PathPoint & (Contap_TheIWLineOfTheIWalking::*)() const ) &Contap_TheIWLineOfTheIWalking::FirstPoint, "Returns the first point of the line when it is a marching point. An exception is raised if HasFirstPoint returns False.");
	cls_Contap_TheIWLineOfTheIWalking.def("FirstPointIndex", (Standard_Integer (Contap_TheIWLineOfTheIWalking::*)() const ) &Contap_TheIWLineOfTheIWalking::FirstPointIndex, "Returns the Index of first point of the line when it is a marching point.This index is the index in the PointStartIterator. An exception is raised if HasFirstPoint returns False.");
	cls_Contap_TheIWLineOfTheIWalking.def("LastPoint", (const IntSurf_PathPoint & (Contap_TheIWLineOfTheIWalking::*)() const ) &Contap_TheIWLineOfTheIWalking::LastPoint, "Returns the last point of the line when it is a marching point. An exception is raised if HasLastPoint returns False.");
	cls_Contap_TheIWLineOfTheIWalking.def("LastPointIndex", (Standard_Integer (Contap_TheIWLineOfTheIWalking::*)() const ) &Contap_TheIWLineOfTheIWalking::LastPointIndex, "Returns the index of last point of the line when it is a marching point.This index is the index in the PointStartIterator. An exception is raised if HasLastPoint returns False.");
	cls_Contap_TheIWLineOfTheIWalking.def("NbPassingPoint", (Standard_Integer (Contap_TheIWLineOfTheIWalking::*)() const ) &Contap_TheIWLineOfTheIWalking::NbPassingPoint, "returns the number of points belonging to Pnts1 which are passing point.");
	cls_Contap_TheIWLineOfTheIWalking.def("PassingPoint", (void (Contap_TheIWLineOfTheIWalking::*)(const Standard_Integer, Standard_Integer &, Standard_Integer &) const ) &Contap_TheIWLineOfTheIWalking::PassingPoint, "returns the index of the point belonging to the line which is associated to the passing point belonging to Pnts1 an exception is raised if Index > NbPassingPoint()", py::arg("Index"), py::arg("IndexLine"), py::arg("IndexPnts"));
	cls_Contap_TheIWLineOfTheIWalking.def("TangentVector", (const gp_Vec & (Contap_TheIWLineOfTheIWalking::*)(Standard_Integer &) const ) &Contap_TheIWLineOfTheIWalking::TangentVector, "None", py::arg("Index"));
	cls_Contap_TheIWLineOfTheIWalking.def("IsTangentAtBegining", (Standard_Boolean (Contap_TheIWLineOfTheIWalking::*)() const ) &Contap_TheIWLineOfTheIWalking::IsTangentAtBegining, "None");
	cls_Contap_TheIWLineOfTheIWalking.def("IsTangentAtEnd", (Standard_Boolean (Contap_TheIWLineOfTheIWalking::*)() const ) &Contap_TheIWLineOfTheIWalking::IsTangentAtEnd, "None");
	cls_Contap_TheIWLineOfTheIWalking.def_static("get_type_name_", (const char * (*)()) &Contap_TheIWLineOfTheIWalking::get_type_name, "None");
	cls_Contap_TheIWLineOfTheIWalking.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Contap_TheIWLineOfTheIWalking::get_type_descriptor, "None");
	cls_Contap_TheIWLineOfTheIWalking.def("DynamicType", (const opencascade::handle<Standard_Type> & (Contap_TheIWLineOfTheIWalking::*)() const ) &Contap_TheIWLineOfTheIWalking::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_SurfProps.hxx
	py::class_<Contap_SurfProps, std::unique_ptr<Contap_SurfProps, Deleter<Contap_SurfProps>>> cls_Contap_SurfProps(mod, "Contap_SurfProps", "Internal tool used to compute the normal and its derivatives.");
	cls_Contap_SurfProps.def(py::init<>());
	cls_Contap_SurfProps.def_static("Normale_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &)) &Contap_SurfProps::Normale, "Computes the point <P>, and normal vector <N> on <S> at parameters U,V.", py::arg("S"), py::arg("U"), py::arg("V"), py::arg("P"), py::arg("N"));
	cls_Contap_SurfProps.def_static("DerivAndNorm_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &)) &Contap_SurfProps::DerivAndNorm, "Computes the point <P>, and normal vector <N> on <S> at parameters U,V.", py::arg("S"), py::arg("U"), py::arg("V"), py::arg("P"), py::arg("d1u"), py::arg("d1v"), py::arg("N"));
	cls_Contap_SurfProps.def_static("NormAndDn_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &)) &Contap_SurfProps::NormAndDn, "Computes the point <P>, normal vector <N>, and its derivatives <Dnu> and <Dnv> on <S> at parameters U,V.", py::arg("S"), py::arg("U"), py::arg("V"), py::arg("P"), py::arg("N"), py::arg("Dnu"), py::arg("Dnv"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_TheIWalking.hxx
	py::class_<Contap_TheIWalking, std::unique_ptr<Contap_TheIWalking, Deleter<Contap_TheIWalking>>> cls_Contap_TheIWalking(mod, "Contap_TheIWalking", "None");
	cls_Contap_TheIWalking.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Step"));
	cls_Contap_TheIWalking.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Step"), py::arg("theToFillHoles"));
	cls_Contap_TheIWalking.def("SetTolerance", (void (Contap_TheIWalking::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &Contap_TheIWalking::SetTolerance, "Deflection is the maximum deflection admitted between two consecutive points on a resulting polyline. Step is the maximum increment admitted between two consecutive points (in 2d space). Epsilon is the tolerance beyond which 2 points are confused", py::arg("Epsilon"), py::arg("Deflection"), py::arg("Step"));
	cls_Contap_TheIWalking.def("Perform", [](Contap_TheIWalking &self, const IntSurf_SequenceOfPathPoint & a0, const IntSurf_SequenceOfInteriorPoint & a1, Contap_SurfFunction & a2, const opencascade::handle<Adaptor3d_HSurface> & a3) -> void { return self.Perform(a0, a1, a2, a3); }, py::arg("Pnts1"), py::arg("Pnts2"), py::arg("Func"), py::arg("S"));
	cls_Contap_TheIWalking.def("Perform", (void (Contap_TheIWalking::*)(const IntSurf_SequenceOfPathPoint &, const IntSurf_SequenceOfInteriorPoint &, Contap_SurfFunction &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Boolean)) &Contap_TheIWalking::Perform, "Searches a set of polylines starting on a point of Pnts1 or Pnts2. Each point on a resulting polyline verifies F(u,v)=0", py::arg("Pnts1"), py::arg("Pnts2"), py::arg("Func"), py::arg("S"), py::arg("Reversed"));
	cls_Contap_TheIWalking.def("Perform", [](Contap_TheIWalking &self, const IntSurf_SequenceOfPathPoint & a0, Contap_SurfFunction & a1, const opencascade::handle<Adaptor3d_HSurface> & a2) -> void { return self.Perform(a0, a1, a2); }, py::arg("Pnts1"), py::arg("Func"), py::arg("S"));
	cls_Contap_TheIWalking.def("Perform", (void (Contap_TheIWalking::*)(const IntSurf_SequenceOfPathPoint &, Contap_SurfFunction &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Boolean)) &Contap_TheIWalking::Perform, "Searches a set of polylines starting on a point of Pnts1. Each point on a resulting polyline verifies F(u,v)=0", py::arg("Pnts1"), py::arg("Func"), py::arg("S"), py::arg("Reversed"));
	cls_Contap_TheIWalking.def("IsDone", (Standard_Boolean (Contap_TheIWalking::*)() const ) &Contap_TheIWalking::IsDone, "Returns true if the calculus was successful.");
	cls_Contap_TheIWalking.def("NbLines", (Standard_Integer (Contap_TheIWalking::*)() const ) &Contap_TheIWalking::NbLines, "Returns the number of resulting polylines. An exception is raised if IsDone returns False.");
	cls_Contap_TheIWalking.def("Value", (const opencascade::handle<Contap_TheIWLineOfTheIWalking> & (Contap_TheIWalking::*)(const Standard_Integer) const ) &Contap_TheIWalking::Value, "Returns the polyline of range Index. An exception is raised if IsDone is False. An exception is raised if Index<=0 or Index>NbLines.", py::arg("Index"));
	cls_Contap_TheIWalking.def("NbSinglePnts", (Standard_Integer (Contap_TheIWalking::*)() const ) &Contap_TheIWalking::NbSinglePnts, "Returns the number of points belonging to Pnts on which no line starts or ends. An exception is raised if IsDone returns False.");
	cls_Contap_TheIWalking.def("SinglePnt", (const IntSurf_PathPoint & (Contap_TheIWalking::*)(const Standard_Integer) const ) &Contap_TheIWalking::SinglePnt, "Returns the point of range Index . An exception is raised if IsDone returns False. An exception is raised if Index<=0 or Index > NbSinglePnts.", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_TheHSequenceOfPoint.hxx
	py::class_<Contap_TheHSequenceOfPoint, opencascade::handle<Contap_TheHSequenceOfPoint>, Contap_TheSequenceOfPoint, Standard_Transient> cls_Contap_TheHSequenceOfPoint(mod, "Contap_TheHSequenceOfPoint", "None");
	cls_Contap_TheHSequenceOfPoint.def(py::init<>());
	cls_Contap_TheHSequenceOfPoint.def(py::init<const Contap_TheSequenceOfPoint &>(), py::arg("theOther"));
	cls_Contap_TheHSequenceOfPoint.def("Sequence", (const Contap_TheSequenceOfPoint & (Contap_TheHSequenceOfPoint::*)() const ) &Contap_TheHSequenceOfPoint::Sequence, "None");
	cls_Contap_TheHSequenceOfPoint.def("Append", (void (Contap_TheHSequenceOfPoint::*)(const Contap_TheSequenceOfPoint::value_type &)) &Contap_TheHSequenceOfPoint::Append, "None", py::arg("theItem"));
	cls_Contap_TheHSequenceOfPoint.def("Append", (void (Contap_TheHSequenceOfPoint::*)(Contap_TheSequenceOfPoint &)) &Contap_TheHSequenceOfPoint::Append, "None", py::arg("theSequence"));
	cls_Contap_TheHSequenceOfPoint.def("ChangeSequence", (Contap_TheSequenceOfPoint & (Contap_TheHSequenceOfPoint::*)()) &Contap_TheHSequenceOfPoint::ChangeSequence, "None");
	cls_Contap_TheHSequenceOfPoint.def_static("get_type_name_", (const char * (*)()) &Contap_TheHSequenceOfPoint::get_type_name, "None");
	cls_Contap_TheHSequenceOfPoint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Contap_TheHSequenceOfPoint::get_type_descriptor, "None");
	cls_Contap_TheHSequenceOfPoint.def("DynamicType", (const opencascade::handle<Standard_Type> & (Contap_TheHSequenceOfPoint::*)() const ) &Contap_TheHSequenceOfPoint::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_TheSequenceOfLine.hxx
	bind_NCollection_Sequence<Contap_Line>(mod, "Contap_TheSequenceOfLine");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_SequenceOfSegmentOfTheSearch.hxx
	bind_NCollection_Sequence<Contap_TheSegmentOfTheSearch>(mod, "Contap_SequenceOfSegmentOfTheSearch");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_SequenceOfPathPointOfTheSearch.hxx
	bind_NCollection_Sequence<Contap_ThePathPointOfTheSearch>(mod, "Contap_SequenceOfPathPointOfTheSearch");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Contap_SequenceOfIWLineOfTheIWalking.hxx
	bind_NCollection_Sequence<opencascade::handle<Contap_TheIWLineOfTheIWalking> >(mod, "Contap_SequenceOfIWLineOfTheIWalking");


}
