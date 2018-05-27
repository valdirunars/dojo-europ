let component = ReasonReact.statelessComponent(__MODULE__);

let config = Maps.pConfig(~scale=200, ~rotation=[| -10, 0, 0 |]);

let didMount = (_self) => {
  Fetcher.fetchGet(~url="https://immense-river-25513.herokuapp.com/locations", ~cb=(dataArr) => {
    Js.log(dataArr);
  });
};

/* underscores before names indicate unused variables. We name them for clarity */
let make = (_children) => {
  ...component,
  didMount,
  render: (_self) => <div>
    <Maps.ComposableMap className="FooBar" config>
      <Maps.ZoomableGroup>
        <Maps.Geographies geography="../world-50m.json">
          ...(
            (geographies: array(Maps.geography), projection: Maps.projection) => {
              Belt.Array.mapWithIndex(geographies, (i: int, geography: Maps.geography) => {
                <Maps.Geography key=(Printf.sprintf("%d", i)) geography projection/>
              })
            }
          )
        </Maps.Geographies>
      </Maps.ZoomableGroup>
    </Maps.ComposableMap>
  </div>
};