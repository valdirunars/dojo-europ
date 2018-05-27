[@bs.deriving abstract]
type pConfig = {
  scale: int,
  rotation: array(int)
};

type geography;
type projection;

[@bs.module "react-simple-maps"]
external composableMap: ReasonReact.reactClass = "ComposableMap"; 

[@bs.module "react-simple-maps"]
external zoomableGroup: ReasonReact.reactClass = "ZoomableGroup"; 

[@bs.module "react-simple-maps"]
external geographies: ReasonReact.reactClass = "Geographies"; 

[@bs.module "react-simple-maps"]
external geographyComponent: ReasonReact.reactClass = "Geography"; 

module ComposableMap = {
  [@bs.deriving abstract]
  type jsProps = {
    className: string,
    projectionConfig: pConfig
  };

  /* 
  [@bs.deriving abstract]
  type Location
  */
  let make = (~className, ~config, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=composableMap,
      ~props=jsProps(~className, ~projectionConfig=config),
      children,
    );
};

module ZoomableGroup = {
  let make = (children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=zoomableGroup,
      ~props=(),
      children,
    );
};

module Geographies = {
  [@bs.deriving abstract]
  type jsProps = {
    geography: string,
  };

  let make = (~geography, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=geographies,
      ~props=jsProps(~geography),
      children,
    );
};

module Geography = {
  [@bs.deriving abstract]
  type jsProps = {
    geography: geography,
    projection: projection
  };

  let make = (~geography, ~projection, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=geographyComponent,
      ~props=jsProps(~geography, ~projection),
      children,
    );
};
